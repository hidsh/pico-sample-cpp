# pico-hid-composite

# build
```
cd pico-hid-composite
ln -s $PICO_SDK_PATH/external/pico_sdk_import.cmake .
mkdir build
cd $_
cmake ..
make -j4
```

# flash into pi-pico 
```
openocd -f interface/picoprobe.cfg -f target/rp2040.cfg -c "program hid-composite.elf verify reset exit"
```

or just use [picoprog.sh](https://gist.github.com/hidsh/4dc19284ddea311825950b2a1be621bc)


# test

Push `BOOTSEL` switch on pi-pico, then...

- from keyboard device: input `a`
- from mouse device: pointer moved to right down
- from consumer controll device: speaker volume -
- from gamepad device: UNKNOWN

# memo

## board_button_read() --> pico-sdk/lib/tinyusb/hw/bsp/rp2040/family.c
```
uint32_t board_button_read(void)
{
#ifdef BUTTON_BOOTSEL
  return BUTTON_STATE_ACTIVE == get_bootsel_button();
#else
  return 0;
#endif
}

```

## PICO_DEFAULT_LED_PIN --> pico-sdk/src/boards/include/boards/pico.h

```
#define PICO_DEFAULT_LED_PIN 25
```
