#
# Oleksandr "tAtaman" Bolbat
# PMiK project "CMakeLists.txt"
#

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# It makes things work
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# It makes things work

set(PICO_BOARD pico2_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK
include(pico_sdk_import.cmake)

project(PMiK C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# All headers
include_directories(${CMAKE_SOURCE_DIR}/Inc/Others/Defines)
include_directories(${CMAKE_SOURCE_DIR}/Inc/Others/Enums)
include_directories(${CMAKE_SOURCE_DIR}/Inc/Others)
include_directories(${CMAKE_SOURCE_DIR}/Inc/CallbackFunctions)
include_directories(${CMAKE_SOURCE_DIR}/Inc/Devices)
include_directories(${CMAKE_SOURCE_DIR}/Inc/Symbols)
include_directories(${CMAKE_SOURCE_DIR}/Inc/Views)

# All source files and main.c
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/Src/Others/*.c
                    ${CMAKE_SOURCE_DIR}/Src/CallbackFunctions/*.c
                    ${CMAKE_SOURCE_DIR}/Src/Devices/*.c
                    ${CMAKE_SOURCE_DIR}/Src/Views/*.c)
add_executable(PMiK main.c ${SRC_FILES})

pico_set_program_name(PMiK "PMiK")
pico_set_program_version(PMiK "0.1")  

pico_enable_stdio_usb(PMiK 1)

# Add the standard library to the build
target_link_libraries(PMiK  pico_stdlib
                            pico_rand
                            pico_cyw43_arch_none
                            hardware_adc
                            hardware_spi)

# Add the standard include files to the build
target_include_directories(PMiK PRIVATE ${CMAKE_CURRENT_LIST_DIR})

pico_add_extra_outputs(PMiK)
