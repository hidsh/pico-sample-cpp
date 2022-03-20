#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define SW_PIN 28       // GPIO#

int main(void) {
    stdio_init_all();
    gpio_init_mask(0xFFFFFFFC);     // initialize gpios other than GP0(TX0) and GP1(RX0)
    gpio_pull_up(SW_PIN);

    uint32_t input;
    uint32_t cnt = 0;

    puts("---------- start ----------");
    while (1) {
        input = gpio_get_all();

        printf("%3d %032b\n", cnt, input);
        cnt = (cnt + 1) % 1000;
        sleep_ms(100);
    }
}
