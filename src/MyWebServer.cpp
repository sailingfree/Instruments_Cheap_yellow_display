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

// The web server
WebServer server(80);

// Web server
void webServerSetup(void) {
    server.begin(80);
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Web server started");

        server.on("/", HTTP_GET, []() {
            server.send(200, "text/html", style +
                head_html +
                index_html +
                nav +
                footer_html);
            server.sendHeader("Connection", "close");
            });

        server.on("/temp", HTTP_GET, []() {
            float temp = getTempC();
            server.sendHeader("Connection", "close");
            server.send(200, "text/html", style +
                head_html +
                "<meta http-equiv='refresh' content='1'>" +
                "<h1>System</h1>" +
                "<h2>" +
                "Temperature: " +
                temp + 
                "&#8451;" +
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
                char * buffer;
                size_t doclen;
                float temp = getTempC();
                doc["temperature"] = temp;
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