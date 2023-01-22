
# Build dependencies
```
sudo apt install git build-essential cmake gcc-arm-none-eabi
```
CMake version must be 3.13 or higher

# Build instructions
```
git clone https://github.com/anticitizn/pico-web-sensor.git
cd pico-web-sensor
./build.sh
```

- Copy `pico_websensor.uf2` into the Pico
- Web server is now available at `192.168.7.1`