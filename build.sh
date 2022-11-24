#!/bin/sh
if [ ! -d "build" ]; then
  mkdir build
fi

./regen-fsdata.sh

cd build
cmake ../
make clean
make