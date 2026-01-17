Build a custom espidf with these instructions:

https://www.positroid.tech/en/post/platformio-esp32-stats

Commands:

On Windows using wsl:
Also ubuntu

# Install missing tools
sudo apt install git pip cmake jq ninja-build

# From the home directory /home/pete
cd espidf-build/

# Get the builder
git clone https://github.com/espressif/esp32-arduino-lib-builder

# setup
cd esp32-arduino-lib-builder
git switch release/v4.4

# Update the build.sh script to disable updates
# Get the script from the scripts folder here
# or edit lines 84-88 as follows
# if [ $SKIP_ENV -eq 0 ]; then
#    echo "* Installing/Updating ESP-IDF and all components..."
    # update components from git
#    ./tools/update-components.sh
#    if [ $? -ne 0 ]; then exit 1; fi


# Get the components
git clone -b v4.4.7 --recursive https://github.com/espressif/esp-idf.git && git -C ./esp-idf/ reset --hard 38eeba213a && git clone -b 2.0.17 --recursive https://github.com/espressif/arduino-esp32 ./components/arduino && git -C ./components/arduino reset --hard d75795f5 && git clone --recursive https://github.com/espressif/esp32-camera ./components/esp32-camera && git -C ./components/esp32-camera reset --hard f0bb429 && git clone --recursive https://github.com/espressif/esp-dl.git ./components/esp-dl && git -C ./components/esp-dl reset --hard 0632d24 && git clone --recursive https://github.com/joltwallet/esp_littlefs.git ./components/esp_littlefs && git -C ./components/esp_littlefs reset --hard 41873c2 && git -C ./components/esp_littlefs submodule update --init --recursive && git clone --recursive https://github.com/espressif/esp-rainmaker.git ./components/esp-rainmaker && git -C ./components/esp-rainmaker reset --hard d8e9345 && git -C ./components/esp-rainmaker submodule update --init --recursive && git clone --recursive https://github.com/espressif/esp-dsp.git ./components/espressif__esp-dsp && git -C ./components/espressif__esp-dsp reset --hard 9b4a8b4 && git clone --recursive https://github.com/hathach/tinyusb.git ./components/arduino_tinyusb/tinyusb && git -C ./components/arduino_tinyusb/tinyusb reset --hard a0e5626bc

# Edit the options if needed
# eg add vtask stats
# CONFIG_FREERTOS_GENERATE_RUN_TIME_STATS=y
# CONFIG_FREERTOS_VTASKLIST_INCLUDE_COREID=y
vim configs/defconfig.esp32

# Install tools
./esp-idf/install.sh

# Build. this takes a long time as it builds different bootloaders and different memory configs
./build.sh -t esp32

# Check the config if needed
idf.py menuconfig

# Copy the build to the .platformio location
cp -r out/tools/sdk/ /mnt/c/Users/peter/.platformio/packages/framework-arduinoespressif32/tools/

# Or create a tar file for copying (about 51MB)
tar cjvf sdk.tar.bz2 out/tools/sdk/

======================================
BME280 code from here https://github.com/bolderflight/bme280/tree/main