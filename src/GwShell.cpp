// Command shell for the NMEA gateway
// Accessed using telnet - yes I know this is insecure, its on the TODO list ok?

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

#include <Arduino.h>
#include <ESP.h>
#include <GwPrefs.h>
#include <GwShell.h>
#include <SimpleSerialShell.h>
#include <StringStream.h>
#include <SysInfo.h>
#include <map>


// Output the ID of the code
static int showID(int argc = 0, char** argv = NULL) {
    shell.println(F("Running " __FILE__ ",\nBuilt " __DATE__));
    return 0;
}

// Show some system information
static int sys(int argc, char** argv) {
    StringStream s;
    getSysInfo(s);
    shell.print(s.data);
    return 0;
}

// Networking information
int net(int argc, char** argv) {
    StringStream s;
    getNetInfo(s);
    shell.print(s.data);
    return 0;
}

// get a preference value and display it
int getval(int argc, char** argv) {
    char* key;
    if (argc != 2) {
        shell.printf("Please supply a register name. Registers are:\n");
        GwListRegs(shell);
        return 0;
    }
    key = argv[1];
    if (!isGwKey(String(key))) {
        shell.printf("%s is not a valid register. Registers are:\n", key);
        GwListRegs(shell);
        return 0;
    }

    String val = GwGetVal(key);
    shell.printf("%s -> %s\n", key, val.c_str());
    return 0;
}

// set a preference value, making validity checks first.
int setval(int argc, char** argv) {
    char* key;
    char* val;

    if (argc != 3) {
        shell.printf("Please supply a register name and new value. Registers are:\n");
        GwListRegs(shell);
        return 0;
    }
    key = argv[1];
    val = argv[2];
    String newval(argv[2]);
    String curval("");

    if (!isGwKey(String(key))) {
        shell.printf("%s is not a valid register. Registers are:\n", key);
        GwListRegs(shell);
        return 0;
    }
    curval = GwSetVal(key, newval);
    if (curval != newval) {
        shell.printf("Error saving register '%s' as '%s' (%s)\n",
                     key, val, curval.c_str());
    } else {
        shell.printf("%s -> %s\n", key, curval.c_str());
    }
    return 0;
}

// Disconnect the terminal session
int quit(int argc, char** argv) {
    disconnect();
    return 0;
}

// Enable/disable logging all debug messages to the terminal
static Stream* old;
int logger(int argc, char** argv) {
    if (argc != 2) {
        shell.printf("Usage: logger on|off\n");
        return (-1);
    }
    if (strcmp(argv[1], "on") == 0) {
        old = Console;
        Console = &shell;
        return 0;
    } else if (strcmp(argv[1], "off") == 0) {
        Console = old;
        return 0;
    } else {
        shell.printf("Usage: logger on|off\n");
        return (-1);
    }
}

// reboot the ESP32 board.
int reboot(int argc, char** argv) {
    ESP.restart();
    return 0;  // I dont think we ever get here
}

// Print the messages that have been seen incoming
int messages(int argc, char** argv) {
    StringStream s;
    getN2kMsgs(s);
    shell.print(s.data);
    return 0;
}

// Initialise the shell and add the commands
// The format of the command is HELP_TEXT<space>CMD
void initGwShell() {
    Serial.println("Initialisting the shell");
    shell.addCommand(F("id \t\tPrint the revision of the system"), showID);
    shell.addCommand(F("sys \t\tPrint the system details"), sys);
    shell.addCommand(F("net \t\tPrint the network details"), net);
    shell.addCommand(F("getval \tGet the value of a setting (getval NAME)"), getval);
    shell.addCommand(F("setval \tSet the value of a setting (setval NAME VALUE)"), setval);
    shell.addCommand(F("quit \t\tExit the shell if connected over a network"), quit);
    shell.addCommand(F("logger \tSet the output logging. (logger on|off)"), logger);
    shell.addCommand(F("reboot \tReboot the ESP"), reboot);
    shell.addCommand(F("msgs \t\tShow the N2K message counts"), messages);
}

// Print a prompt to the terminal
void doPrompt() {
    shell.printf("%s Ok>", host_name.c_str());
}

void setShellSource(Stream* telnetClient) {
    if (telnetClient) {
        shell.attach(*telnetClient);
    } else {
        Serial.printf("Cannot attach shell - no client\n");
    }
}

// Check to see if there is anything to do, if there is it is executed.
// Output a prompt if something is done.
void handleShell() {
    int didsomething = shell.executeIfInput();
    if (didsomething) {
        doPrompt();
    }
}
