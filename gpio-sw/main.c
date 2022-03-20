#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define SW_PIN 28       // GPIO#

int main(void) {
    stdio_init_all();
    gpio_init_mask(0xFFFFFFFC);     // initialize gpios other than GP0(TX0) and GP1(RX0)
    gpio_pull_up(SW_PIN);

    bool sw;
    uint32_t cnt = 0;

    puts("---------- start ----------");
    while (1) {
        sw = gpio_get(SW_PIN);

        printf("%3d %d\n", cnt, sw);
        cnt = (cnt + 1) % 1000;
        sleep_ms(500);
    }
}
