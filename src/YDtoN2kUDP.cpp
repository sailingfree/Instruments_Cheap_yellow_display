//////////////////////////////////////////////////////////////////////////////////////////////////
// Class to read Yacht Data (YD) formatted NMEA2000 messages from a UDP port.
// To use:
// 1. Instantiate an object of this class.
// 2. Once you have a network up and running - eg wifi. call the begin method with the port.
// 3. Read the data periodically into the caller supplied n2kmsg object . 
// If there is no data then the read method returns false and the caller's ns2msg object is untouched.
// 
// //////////////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////////////////


#include <YDtoN2KUDP.h>
#include <GwLogger.h>

// Constructor
YDtoN2kUDP::YDtoN2kUDP() {
}

// Initialise the wifiudp object to listen on the supplied port.
void YDtoN2kUDP::begin(uint16_t port) {
    wifiUdp.begin(port);
}

// read the YD data from the UDP port. If no data return false
// otherwise decode the data into the callers supplied object
bool YDtoN2kUDP::readYD(tN2kMsg &msgout)
{
  static uint32_t seq = 0;      // Used for debugging
  static const int debug = 0;   // Set to 1 for debug messages
  static const int debug2 = 0;  // set to 1 to print the YD messages only
  bool hadpacket = false;       // Return value

    // Read and parse the data from the UDP port.
  int packetSize = wifiUdp.parsePacket();
  if (packetSize) {
    if(debug) {
      Serial.printf("Received packet %d of size %d", seq++, packetSize);
      Serial.print("From ");
      IPAddress remoteIp = wifiUdp.remoteIP();
      Serial.println(remoteIp);
    }

    // read the packet into packetBufffer
    int len = wifiUdp.read(packetBuffer, N2K_PKT_SIZE);
    if (len > 0) {
      packetBuffer[len] = 0;
    }

    if(debug2) {
      // Packet already has new line
      unsigned long now = millis();

      Serial.print(now);
      Serial.print(" ");
      Serial.print(packetBuffer);
    }
 
    // Break the message into components.
    char * word;
    const char * sep = " ";
    char * lasts;
    int i = 0;
    const uint16_t maxwords = 64;
    const uint16_t maxlen   = 16;
    char words[maxwords][maxlen];

    for (word = strtok_r(packetBuffer, sep, &lasts);
                word && i < maxwords;
                word = strtok_r(NULL, sep, &lasts), i++) {
        strncpy(words[i], word, maxlen - 1);
        if(debug2) {
            Serial.printf(" (%d) %s", i, word);
        }
    }

    if(debug2) {
        Serial.println();
        Serial.printf("Len %d\n", i);
    }

    // Unpack the CAN ID into it parts and build the n2kmsg object
    // The format is explained here https://endige.com/2050/nmea-2000-pgns-deciphered/
    if(i > 2) {
      // word[0] = time
      // word[1] = direction
      // word[2] = canid
      // word[3 to maxwords-1] = data values

      // Get the canId and extract the sender station and the PGN
      // The source is the bottom 8 bits
      uint32_t canId = strtoul((const char *) words[2], NULL, 16);
      uint32_t len = i - 3; 

      uint32_t source = canId & 0xff;
      uint32_t PGN = (canId >> 8) & 0x3ffff;
      uint32_t PRIO = (canId >> 26) & 0x7;
     
      msgout.Source = source;
      msgout.Priority = PRIO;
      msgout.SetPGN(PGN);
      msgout.DataLen = len;
      for(int j = 0; j < len; j++) {
        msgout.Data[j] = strtoul((const char *)words[j+3], NULL, 16) & 0xff;
    }
    if(debug) {
      Serial.printf("SRC %d PGN %d\n", source, PGN);
    }
    hadpacket = true;
    }
  }
  return hadpacket;
}

