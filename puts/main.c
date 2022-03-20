#include <stdio.h>
#include "pico/stdlib.h"    // stdio_init_all, sleep_ms

int main() {

    stdio_init_all();

    while(1) {
        puts("Hello World\n");
        sleep_ms(1000);
    }
}

// test using gnu screen:
// $ screen /dev/cu.usbmodem142101 115200
