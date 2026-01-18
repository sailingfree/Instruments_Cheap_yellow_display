#include <Arduino.h>

#include <WiFi.h>

#include <WebServer.h>

#include <StringStream.h>
#include <SysInfo.h>
#include <sensors.h>

// HTML strings
#include <html/style.html>  // Must come before the content files
#include <html/index.html>
#include <html/login.html>

// Json library
#include <ArduinoJson.h>

#include <StreamString.h>

extern Stream * Console;

// The web server
WebServer server(80);

// Web server
void webServerSetup(void) {
    server.begin(80);
    if (WiFi.status() == WL_CONNECTED) {
        Console->println("Web server started");

        server.on("/", HTTP_GET, []() {
            server.send(200, "text/html", style +
                head_html +
                index_html +
                nav +
                footer_html);
            server.sendHeader("Connection", "close");
            });

        server.on("/temp", HTTP_GET, []() {
            struct tm tm;
            char buf[32];
            time_t now = time(NULL);
            gmtime_r(&now, &tm);

            snprintf(buf, 9, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
            float temprawC = getTempC();
            float temprawF = getTempF();
            // Round to nearest 0.5
            float temp = round((temprawC * 2.0)) / 2.0;
            server.sendHeader("Connection", "close");
            server.send(200, "text/html", style +
                head_html +
                "<meta http-equiv='refresh' content='1'>" +
                "<h1>System</h1>" +
                "<h2>" +
                "Temperature: " +
                temprawC + 
                "&#8451;" +
                " &nbsp " +
                temp + 
                "&#8451;" +
                " &nbsp " +
                roundf(temprawF * 2.0) / 2.0 + "&#8457;" +
                "</h2>" +
                "<h2>" +
                "Time: " +
                buf + 
                "</h2>" +
                nav +
                footer_html);
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

            server.on("/json", HTTP_GET, []() {
                JsonDocument doc;
                float temp = getTempC();
                float pres = getPressure();
                float humi = getHumidity();

                // Round to 0.5
                temp = round(temp * 2.0) / 2.0;
                doc["temperature"] = temp;
                doc["pressure"] = pres;
                doc["humidity"] = humi;
                
                WiFiClient client = server.client();
               // Write response headers
                client.println(F("HTTP/1.0 200 OK"));
                client.println(F("Content-Type: application/json"));
                client.println(F("Connection: close"));
                client.print(F("Content-Length: "));
                client.println(measureJsonPretty(doc));
                client.println();

                // Write JSON document
                serializeJsonPretty(doc, client);
                StreamString str;
                serializeJsonPretty(doc, str);

                // Disconnect
                client.stop();
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