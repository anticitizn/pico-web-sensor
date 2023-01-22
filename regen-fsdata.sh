#!/bin/sh

if [ ! -f makefsdata ]; then
    # Doing this outside cmake as we don't want it cross-compiled but for host
    echo Compiling makefsdata
    gcc -o src/makefsdata -Iexternal/lwip/src/include -Isrc/ -Iexternal/ -I. external/lwip/src/apps/http/makefsdata/makefsdata.c
fi

echo Regenerating fsdata.c
./src/makefsdata 
echo Done
