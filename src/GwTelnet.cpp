// Telnet handler

/*
Copyright (c) 2022 Peter Martin www.naiadhome.com

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <GwTelnet.h>

void disconnect() {
    telnetClient.stop();
}

void handleTelnet() {
    if (telnetClient && telnetClient.connected()) {
        // Got a connected client so use it
    } else {
        // See if there is a new connection and assign the new client
        telnetClient = telnet.available();
        if (telnetClient) {
            // Set up the client
            // telnetClient.setNoDelay(true); // More faster
            telnetClient.flush();  // clear input buffer, else you get strange characters
            setShellSource(&telnetClient);
            Serial.printf("Telnet client connected\n");
        }
    }

    if (!telnetClient) {
        setShellSource(&Serial);
        return;
    }
}
