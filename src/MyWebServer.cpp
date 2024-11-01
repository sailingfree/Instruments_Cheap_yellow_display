#include <Arduino.h>

#include <WiFi.h>

#include <WebServer.h>

#include <tftscreen.h>

#include <StringStream.h>

#include <sdcard.h>
#include <SdFat.h>
#include <SysInfo.h>

// HTML strings
#include <html/style.html>  // Must come before the content files
#include <html/index.html>
#include <html/login.html>
//#include <html/server_index.html>


// The web server
WebServer server(80);


void handleFileUpload() {
    Serial.println("In handle upload");
    HTTPUpload &upload = server.upload();
    if(upload.status == UPLOAD_FILE_START) {
        String filename = upload.filename;
    } else if(upload.status == UPLOAD_FILE_WRITE) {
        Serial.printf("BUF %d %s\n", upload.currentSize, upload.buf);
    }
}

class uriHandler : public RequestHandler {
public:
    uriHandler() {
        Serial.printf("uriHandler registered\n");
    }

    bool canHandle(HTTPMethod requestMethod, String uri) override {
        bool result = false;
        
        if((requestMethod != HTTP_GET))  {
            return false;
        }
        if(uri.endsWith(".html")) {
            Serial.printf("URI %s end s with .html\n", uri.c_str());
            result = true;
        }
        return result;
    }

    bool handle(WebServer & server, HTTPMethod method, String requestUri) override {
        Serial.printf("URI %s\n", requestUri);
        const int bsize = 4096;
        char buf[bsize];
        Serial.printf("In handler for %s\n", requestUri.c_str());
        if(!file.open(requestUri.c_str(), O_RDONLY)) {
            server.send(404, "text/html", "No such file");
            return false;
        } else {
            server.setContentLength(file.dataLength());
            server.sendHeader("Content-Type", "text/html");
            server.send(200, "text/html", "");
            server.sendHeader("Connection", "close");
                    
            uint32_t count =0;
            int c;
            do {
                c = file.readBytes(buf, bsize);  
                server.sendContent(buf, c); 
                count += c;
            } while (c);
            file.close();

         //   server.send(200);
            return true;
        }
    }
};

// Web server
void webServerSetup(void) {
    server.begin(80);
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Web server started");
        displayText("Web Server started");

        server.addHandler(new uriHandler());

         // This works for a POST with a content encoding of text/plain though application/json also appears to work
        // The result ends up in a header called plain.
        // The file to write to is on the command line as ?file=filename
        server.on("/", HTTP_POST, []() {
            const uint16_t blen = 32;
            int datalen = server.clientContentLength();
            Serial.printf("POST...\n");
            Serial.printf("length %d\n", datalen);
            int nargs = server.args();
            Serial.printf("There are %d args\n", nargs);
            String body;
            String filename;
            for(int i = 0; i < nargs; i++) {
                String argname = server.argName(i);
                String arg = server.arg(i);
                Serial.printf("Arg %d => %s = %s\n", i, argname.c_str(), arg.c_str());
                if(argname == "plain") {
                    body = arg;
                }
                if(argname == "file") {
                    filename = arg;
                }
            }
            if(filename == "") {
                server.send(404, "application/octet-stream", "No filename supplied");
            } else {
            Serial.printf("Body: %s\n", body.c_str());
            Serial.printf("Filename %s\n", filename.c_str());
            server.send(200, "text/plain", "");
            file.open(filename.c_str(), O_CREAT | O_WRITE | O_TRUNC);
            file.write(body.c_str(), body.length());
            file.close();
            }
        },
        handleFileUpload
        );

        server.on("/", HTTP_GET, []() {
            server.send(200, "text/html", style + 
                                            head_html + 
                                            index_html + 
                                            nav + 
                                            footer_html);
            server.sendHeader("Connection", "close");
            });

        server.on("/system", HTTP_GET, []() {
            StringStream net, sys, msgs;
            getNetInfo(net);
            getSysInfo(sys);
            getN2kMsgs(msgs);
            server.sendHeader("Connection", "close");
            server.send(200, "text/html", style + 
                    head_html + 
                    "<h1>System</h1>" +
                    "<pre>" + 
                    net.data + 
                    sys.data + 
                    msgs.data + 
                    "</pre>" + 
                    nav +
                    footer_html);
            });

        // Handle downloading a logfile
        server.on("/download", HTTP_GET, []() {
            // Default logfile is the current one
            String logname("logfile.txt");

            int nargs = server.args();
            Serial.printf("There are %d args\n", nargs);
            for(int i = 0; i < nargs; i++) {
                String argname = server.argName(i);
                String arg = server.arg(i);
                Serial.printf("Arg %d => %s = %s\n", i, argname.c_str(), arg.c_str());
                if(argname == "file") {
                    logname = arg;
                }
            }

            if (!file.open(logname.c_str(), O_RDWR)) {
                errorPrint("Reading logfile\n");
                server.send(404, "application/octet-stream", "No such file");
            }
            else {
                Serial.printf("Downloading logfile %s\n", logname.c_str());
                uint32_t filesize = file.size();
                Serial.printf("Opened... %d bytes\n", filesize);

                char* buf;
                const size_t bsize = 8192;
                buf = (char*)malloc(bsize);
                if (!buf) {
                    Serial.printf("Cannot allocate %d bytes for download\n", 8192);
                }
                else {
                    server.setContentLength(CONTENT_LENGTH_UNKNOWN);
                    server.sendHeader("Content-Type", "application/octet-stream");
                    server.sendHeader("Content-Disposition", "attachment; filename=logfile.txt");
                    server.send(200, "application/octet-stream", "");
                    
                    ulong start = micros();
                    uint32_t count =0;
                    int c;
                    do {
                        c = file.readBytes(buf, bsize);  
                        //memset(buf,'$', bsize); if(count > 819200) {c = 0;} else {c = bsize;}
                        server.sendContent(buf, c); 
                        count += c;
                    } while (c);
                    ulong now = micros();
                    Serial.printf("Read %d bytes in %d usecs = %.2f kbytes/sec\n", 
                        count, now - start, (float)count / ((now - start) / 1000.0));
                    file.close();
                    free(buf);
                }
            }

            server.sendHeader("Connection", "close");
            });

                    delay(10);
                    server.begin();
    }
}

void webServerWork() {
    if (WiFi.status() == WL_CONNECTED) {
        server.handleClient();
    }
}