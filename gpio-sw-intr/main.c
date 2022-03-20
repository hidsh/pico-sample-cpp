#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/sync.h"  // save_and_disable_interrupts, restore_interrupts

#define SW_PIN 28       // GPIO#

void gpio_callback(uint pin, uint32_t events) {
    uint32_t bak = save_and_disable_interrupts();

    if(pin == SW_PIN)
        puts("interrupt!");

    restore_interrupts(bak);
}

int main(void) {
    stdio_init_all();
    gpio_init_mask(0xFFFFFFFC);     // initialize gpios other than GP0(TX0) and GP1(RX0)
    gpio_pull_up(SW_PIN);

    gpio_set_irq_enabled_with_callback(28, GPIO_IRQ_EDGE_FALL, true, gpio_callback);

    uint32_t cnt = 0;

    puts("---------- start ----------");
    while (1) {
        printf("%3d\n", cnt);
        cnt = (cnt + 1) % 1000;
        sleep_ms(500);
    }
}
