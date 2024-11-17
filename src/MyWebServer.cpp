#include <Arduino.h>

#include <WiFi.h>

#include <WebServer.h>

#include <StringStream.h>
#include <SysInfo.h>

// HTML strings
#include <html/style.html>  // Must come before the content files
#include <html/index.html>
#include <html/login.html>

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

        delay(10);
        server.begin();
    }
}

void webServerWork() {
    if (WiFi.status() == WL_CONNECTED) {
        server.handleClient();
    }
}