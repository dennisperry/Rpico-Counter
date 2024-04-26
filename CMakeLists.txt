# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set_property(GLOBAL APPEND PROPERTY HEX_FILES_TO_MERGE
      ${app_provision_hex})

# Suppress "simple_bus_reg" on Pico boards as all GPIO ports use the same register.
list(APPEND EXTRA_DTC_FLAGS "-Wno-simple_bus_reg")

set(BOARD rpi_pico_w)

find_package(Zephyr)
project(counter)

target_sources(app PRIVATE src/main.c)

# zephyr_compile_options(-save-temps)
