#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "pio_test.pio.h"   // generating by cmake

const uint LED_PIN = 25;

void main(void)
{
    PIO pio = pio0;
        /* PIO0を使用する。 */

    uint offset = pio_add_program(pio, &pio_test_program);
        /* 指定したPIOのインストラクションメモリにプログラムをロードする */
        /* プログラムの先頭アドレス(オフセット)が戻り値として返ってくる */

    uint sm = pio_claim_unused_sm(pio, true);
        /* 指定したPIOインスタンスの使用していないステートマシンを取得 */

//  pio_test_program_init(PIO pio, uint sm, uint offset, uint out_base, uint out_pin_num);
    pio_test_program_init(pio, sm, offset, LED_PIN, 1);

    while (1)
    {
        pio_sm_put_blocking(pio, sm, 0x0001);
        sleep_ms(500);

        pio_sm_put_blocking(pio, sm, 0x0000);
        sleep_ms(500);

    }
}
