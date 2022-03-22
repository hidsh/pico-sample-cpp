cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

set(proj_name pio-blink)
project(${proj_name} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(${proj_name}
  main.c
)

pico_generate_pio_header(${proj_name} ${CMAKE_CURRENT_LIST_DIR}/pio_test.pio)

target_sources(${proj_name} PRIVATE main.c)

target_link_libraries(${proj_name} PRIVATE
        pico_stdlib
        hardware_pio
        )

pico_add_extra_outputs(${proj_name})
