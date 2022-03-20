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

const uint8_t hid_report_desc[] = {
    TUD_HID_REPORT_DESC_GENERIC_INOUT(1)
};

const uint8_t conf_desc[] = {
    TUD_CONFIG_DESCRIPTOR(1, 1, 0, TUD_CONFIG_DESC_LEN + TUD_HID_INOUT_DESC_LEN, 0, 0x0F),
    TUD_HID_INOUT_DESCRIPTOR(1, 0, 0, sizeof(hid_report_desc), 0x01, 0x81, 64, 0x0F)
};

const uint16_t string_desc_lang[] = { // Index: 0
    4 | (3 << 8), // bLength & bDescriptorType
    0x411 // ja-JP
};

const uint16_t string_desc_product[] = { // Index: 1
    24 | (3 << 8),
    // 'R', 'a', 's', 'p', 'i', 'c', 'o'
    'p', 'i', 'c', 'o', ' ', '(', 'H', 'I', 'D', '3', ')'
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
void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize) {
    uint8_t buf[] = {
        buffer[0] + 1
    };
    tud_hid_n_report(0, 0, buf, 1);
    return;
}

uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen) {
    return 0;
}

uint8_t const * tud_hid_descriptor_report_cb(uint8_t instance) {
    return hid_report_desc;
}


int main() {

	board_init();
	tusb_init();

	while(1) {
		tud_task();
	}

	return 0;
}


