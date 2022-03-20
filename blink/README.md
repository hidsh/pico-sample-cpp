# pi-pico-c-blink

# build
```
cd pi-pico-c-blink
ln -s $PICO_SDK_PATH/external/pico_sdk_import.cmake .
mkdir build
cd $_
cmake ..
make -j4
```

# flash into pi-pico 
```
#cd pi-pico-c-blink/build

openocd -f interface/picoprobe.cfg -f target/rp2040.cfg -c "program blink.elf verify reset exit"
```

or just use [picoprog.sh](https://gist.github.com/hidsh/4dc19284ddea311825950b2a1be621bc)

# check the output from pi-pico

```
screen /dev/tty.usbmodem142401

Hello World

Hello World

Hello World
   :

(type C-a C-\ then y to exit)
```

# check info via picotool

```
picotool info -bp -f
The device was asked to reboot into BOOTSEL mode so the command can be executed.

Program Information
 name:         blink
 description:  This is a test binary.
 features:     UART stdin / stdout
               USB stdin / stdout

Fixed Pin Information
 0:   UART0 TX
 1:   UART0 RX
 25:  On-board LED

      The device was asked to reboot back into application mode.
```
