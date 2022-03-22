#include <stdio.h>          // puts, printf
#include "hardware/gpio.h"  // gpio_*, GPIO_IRQ_*

#include "mouse.h"

#define PIN_MS_BTN_L 20       // GP#
#define PIN_MS_BTN_M 19
#define PIN_MS_BTN_R 18

const uint8_t pin_btn[] = {PIN_MS_BTN_R, PIN_MS_BTN_M, PIN_MS_BTN_L};
Mouse ms = Mouse(pin_btn);

int main(void) {
    stdio_init_all();
    gpio_init_mask(0xFFFFFFFC);     // initialize gpios other than GP0(TX0) and GP1(RX0)


    uint32_t cnt = 0;

    puts("---------- start ----------");
    while (1) {
        MouseData ms_data = ms.get();
        printf("%3d| %03b\n", cnt, ms_data.buttons);    // LMR

        cnt = (cnt + 1) % 1000;
        sleep_ms(500);
    }
}
