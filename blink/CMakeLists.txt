cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

set(proj_name blink)                 # proj_name
project(${proj_name} C CXX ASM)
set(CMAKE_C_STNDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(${proj_name}
  main.c
)

pico_enable_stdio_usb(${proj_name} 1)
pico_enable_stdio_uart(${proj_name} 1)

pico_add_extra_outputs(${proj_name})

target_link_libraries(${proj_name} pico_stdlib)
