#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "tusb.h"
#include "bsp/board.h"


const uint8_t device_desc[] = {
    18, // bLength
    1, // bDescriptorType
    0x10,
    0x01, // bcdUSB
    0x00, // bDeviceClass
    0x00, // bDeviceSubClass
    0x00, // bDeviceProtocol
    CFG_TUD_ENDPOINT0_SIZE, // bMaxPacketSize0
    0x34,
    0x12, // idVendor
    0xcd,
    0xab, // idProduct,
    0x00,
    0x00, // bcdDevice
    0x00, // iManufacturer
    0x01, // iProduct
    0x00, // iSerialNumber
    0x01, // bNumConfigurations
};

const uint8_t conf_desc[] = {
    9, // bLength
    2, // bDescriptorType
    9 + 9,
    0, // wTotalLength
    1, // bNumInterface
    1, // bConfigurationValue
    0, // iConfiguration
    0x20, // bmAttributes
    0x0F, // bMaxPower

    // --- Interface ---
    9, // bLength
    4, // bDescriptorType
    1, // bInterfaceNumber
    0, // bAlternateSetting
    0, // bNumEndpoints
    0xFF, // bInterfaceClass
    0xFF, // bInterfaceSubClass
    0xFF, // bInterfaceProtocol
    0, // iInterface
};

const uint16_t string_desc_lang[] = { // Index: 0
    4 | (3 << 8), // bLength & bDescriptorType
    0x411 // ja-JP
};

const uint16_t string_desc_product[] = { // Index: 1
    32 | (3 << 8),
    // 'R', 'a', 's', 'p', 'i', 'c', 'o'
    't', 'i', 'n', 'y', 'u', 's', 'b', ' ', 'o', 'n', ' ', 'p', 'i', 'c', 'o'
};

uint8_t const * tud_descriptor_device_cb(void) {
	return device_desc;
}
uint8_t const * tud_descriptor_configuration_cb(uint8_t index) {
	return conf_desc;
}
uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid) {
    uint16_t const *ret = NULL;
    switch(index) {
        case 0:
            ret = string_desc_lang;
            break;
        case 1:
            ret = string_desc_product;
            break;
        default:
            break;
    }
    return ret;
}

int main() {

	board_init();
	tusb_init();

	while(1) {
		tud_task();
	}

	return 0;
}


