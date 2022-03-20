# gpio-sw-intr : raspberry pi pico c/c++ sample program

# build
```
cd gpio-sw-intr
ln -s $PICO_SDK_PATH/external/pico_sdk_import.cmake .
mkdir build
cd $_
cmake ..
make -j4
```

# flash into pi-pico 
```
openocd -f interface/picoprobe.cfg -f target/rp2040.cfg -c "program gpio-sw-intr.elf verify reset exit"
```

or use [picoprog.sh](https://gist.github.com/hidsh/4dc19284ddea311825950b2a1be621bc)
```
picoprog.sh gpio-sw-intr.elf
```

# check the output from pi-pico using picoprobe

```
screen /dev/cu.usbmodem142101 115200

  1
  2
interrupt!
interrupt!
interrupt!
  3
  4
   :

(type C-a C-\ then y to exit)
```

