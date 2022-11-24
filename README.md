# purpose of this fork

Experimenting serving dynamic content as described at https://github.com/maxnet/pico-webserver/issues/3

In fact it works well. Not as much as I'd like, but well.
I would like to send files of arbitrary size, but it stops at 12'582'721 bytes, which
is one less than 65536 (16 bit counter) the size of the individual packet (192 bytes).

One could work around that, but I am not doing it, because... The transfer rates
are at most `136 kB / s` and often around `90-100 kB / s` which is a bit too slow for what
I need. Instead, for my purpose I am experimenting with https://github.com/davidedelvento/no-OS-FatFS-SD-SPI-RPi-Pico


# pico-webserver

Webserver example that came with TinyUSB slightly modified to run on a Raspberry Pi Pico.
Lets the Pico pretend to be a USB Ethernet device. Runs a webinterface at http://192.168.7.1/

## Build dependencies

On Debian:

```
sudo apt install git build-essential cmake gcc-arm-none-eabi
```

Your Linux distribution does need to provide a recent CMake (3.13+).
If not, compile [CMake from source](https://cmake.org/download/#latest) first.

## Build instructions

```
git clone --depth 1 https://github.com/maxnet/pico-webserver
cd pico-webserver
git submodule update --init
mkdir -p build
cd build
cmake ..
make
```

Copy the resulting pico_webserver.uf2 file to the Pico mass storage device manually.
Webserver will be available at http://192.168.7.1/

Content it is serving is in /fs
If you change any files there, run ./regen-fsdata.sh

By default it shows a webpage that led you toggle the Pico's led, and allows you to switch to BOOTSEL mode.
