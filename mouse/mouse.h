#include "pico/stdlib.h"
#include "hardware/gpio.h"  // gpio_*, GPIO_IRQ_*

typedef struct {
    uint8_t buttons;        // xxxx_xLMR (1:on)
    int8_t x;
    int8_t y;
    int8_t v;
    int8_t h;
} MouseData;

class Mouse {
private:
    static uint m_pin_btn[3];
    static MouseData m_data;
    static void callback(uint pin, uint32_t events) {
        // uint32_t bak = save_and_disable_interrupts();

        for(int i=0; i<3; i++) {
            // printf("%08b\n", events);

            if(pin == m_pin_btn[i]) {
                if((events & GPIO_IRQ_EDGE_FALL) != 0) {
                    m_data.buttons |= (1 << i);
                }
                else if((events & GPIO_IRQ_EDGE_RISE) != 0) {
                    m_data.buttons &= ~(1 << i);
                }
                else {
                    // othewise sustained
                }
            }
        }

        // restore_interrupts(bak);
    }

public:
    Mouse(const uint8_t pin_btn[]) {
        assert(sizeof(pin_btn) == 3);       // {RIGHT, MIDDLE, LEFT}

        // buttons
        for(int i=0; i<3; i++) {
            uint pin = pin_btn[i];
            m_pin_btn[i] = pin;
            gpio_pull_up(pin);
            gpio_set_input_hysteresis_enabled(pin, true);
            gpio_set_irq_enabled_with_callback(pin,
                          GPIO_IRQ_EDGE_RISE|GPIO_IRQ_EDGE_FALL, true, callback);
        }
    }

    MouseData get() {return m_data;}
};

