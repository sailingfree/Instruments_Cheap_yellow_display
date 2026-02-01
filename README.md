# Build a custom espidf 

This doc describes how I build a custom espidf for use with the Arduino platform on platformio. I wanted to do this for several reasons:

- ESP don't seem to want to update the Arduino libraries for use with Platformio anmore.
- The esp arduino library does not enable some additional features I want such as real time task stats. 
- The alternative pioarduino looks promising, but as of this writing I don't find it stable enough to use for production. I sometimes get tons of library errors and I need to reset to a clean state to get a good compile. This might change!
- I use the Arduino libraries for smoe of the main features of my current projects like the NMEA2000 instruments I'm building, so I don't really want to have to drop these and rewrite a bunch of stuff in the native esp idf, though that may change if I start using some of the newer chips.

So with these instructions I build a custom library. This is based heavily on the work here:

https://www.positroid.tech/en/post/platformio-esp32-stats

### Environment

This has been tested on Windows 11 using WSL, and native Ubuntu 24 desktop and my Mac running Tahoe 26.1

The package versions installed on my machine are:
- framework-arduinoespressif32 @ 3.20017.241212+sha.dcc1105b 
 - tool-esptoolpy @ 1.40501.0 (4.5.1) 
 - tool-openocd-esp32 @ 2.1100.20220706 (11.0) 
 - toolchain-xtensa-esp32 @ 8.4.0+2021r2-patch5
 - 
### Install missing tools
This is for Ubuntu and only needs to be done once.

>sudo apt install git pip cmake jq ninja-build

### From the home directory /home/pete
>cd espidf-build/

### Get the builder
>git clone https://github.com/espressif/esp32-arduino-lib-builder

### Setup

>cd esp32-arduino-lib-builder
>git switch release/v4.4

Update the build.sh script to disable updates
Get the script from the scripts folder here or edit lines 84-88 as follows to comment out the section that updates the components
> if [ $SKIP_ENV -eq 0 ]; then 
>  
>    \#echo "* Installing/Updating ESP-IDF and all components..."
>    \# update components from git
>    \#./tools/update-components.sh
>    \#if [ $? -ne 0 ]; then exit 1; fi


### Get the components

This only needs to be done once

git clone -b v4.4.7 --recursive https://github.com/espressif/esp-idf.git && git -C ./esp-idf/ reset --hard 38eeba213a && git clone -b 2.0.17 --recursive https://github.com/espressif/arduino-esp32 ./components/arduino && git -C ./components/arduino reset --hard d75795f5 && git clone --recursive https://github.com/espressif/esp32-camera ./components/esp32-camera && git -C ./components/esp32-camera reset --hard f0bb429 && git clone --recursive https://github.com/espressif/esp-dl.git ./components/esp-dl && git -C ./components/esp-dl reset --hard 0632d24 && git clone --recursive https://github.com/joltwallet/esp_littlefs.git ./components/esp_littlefs && git -C ./components/esp_littlefs reset --hard 41873c2 && git -C ./components/esp_littlefs submodule update --init --recursive && git clone --recursive https://github.com/espressif/esp-rainmaker.git ./components/esp-rainmaker && git -C ./components/esp-rainmaker reset --hard d8e9345 && git -C ./components/esp-rainmaker submodule update --init --recursive && git clone --recursive https://github.com/espressif/esp-dsp.git ./components/espressif__esp-dsp && git -C ./components/espressif__esp-dsp reset --hard 9b4a8b4 && git clone --recursive https://github.com/hathach/tinyusb.git ./components/arduino_tinyusb/tinyusb && git -C ./components/arduino_tinyusb/tinyusb reset --hard a0e5626bc

### Edit the options if needed

eg add vtask stats

Add this to the end of the config file *configs/defconfig.esp32*

>CONFIG_FREERTOS_GENERATE_RUN_TIME_STATS=y
>CONFIG_FREERTOS_VTASKLIST_INCLUDE_COREID=y

### Install tools
./esp-idf/install.sh

### Build. 
This takes some time as it builds different bootloaders and different memory configs. On my AMD rig with a AMD Ryzen 5 9600X 6-Core Processor this takes about two minutes.
>./build.sh -t esp32

### Check the config if needed
>idf.py menuconfig

### Copy the build to the .platformio location
>cp -r out/tools/sdk/ ~/.platformio/packages/framework-arduinoespressif32/tools/

### Or create a tar file for copying (about 51MB)
>tar cjvf sdk.tar.bz2 out/tools/sdk/

This file can be copied to other machines you use for building applications.
