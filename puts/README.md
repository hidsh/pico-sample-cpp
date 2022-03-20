# puts : raspberry pi pico c/c++ sample program

# build
```
cd puts
ln -s $PICO_SDK_PATH/external/pico_sdk_import.cmake .
mkdir build
cd $_
cmake ..
make -j4
```

# flash into pi-pico 
```
openocd -f interface/picoprobe.cfg -f target/rp2040.cfg -c "program sample.elf verify reset exit"
```

or use [picoprog.sh](https://gist.github.com/hidsh/4dc19284ddea311825950b2a1be621bc)
```
picoprog.sh sample.elf
```

# check the output from pi-pico using picoprobe

```
screen /dev/cu.usbmodem142101 115200

Hello World

Hello World

Hello World
   :

(type C-a C-\ then y to exit)
```

