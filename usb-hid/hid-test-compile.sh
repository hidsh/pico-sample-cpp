#!/bin/sh
gcc $(pkg-config --cflags --libs hidapi) -Wall -o hid-test hid-test.c

