#include <stdio.h>
#include <stdlib.h>
#include <hidapi.h>

unsigned char buf[10];

int main(int argc, char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: hid-test INT_NUMBER\n");
        return 1;
    }

    hid_init();

    hid_device* handle = hid_open(0x1234, 0xabcd, NULL);
    if(handle == NULL) {
        fprintf(stderr, "Failed to open device.\n");
        return 1;
    }

    buf[0] = 0;     // report id
    buf[1] = atoi(argv[1]);
    int ret = hid_write(handle, buf, 2);
    printf("Data sent. Return Code: %d\n", ret);

    hid_read(handle, buf, 1);
    printf("Data Read: %d\n", buf[0]);

    hid_close(handle);
    hid_exit();

    return 0;
}
