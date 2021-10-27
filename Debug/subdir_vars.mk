################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../cc13x2_cc26x2_tirtos.cmd 

SYSCFG_SRCS += \
../uartecho.syscfg 

C_SRCS += \
../events.c \
../led.c \
../main_tirtos.c \
../nvs.c \
../ti_printf.c \
../uartecho.c \
./syscfg/ti_devices_config.c \
./syscfg/ti_drivers_config.c 

GEN_FILES += \
./syscfg/ti_devices_config.c \
./syscfg/ti_drivers_config.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./events.d \
./led.d \
./main_tirtos.d \
./nvs.d \
./ti_printf.d \
./uartecho.d \
./syscfg/ti_devices_config.d \
./syscfg/ti_drivers_config.d 

OBJS += \
./events.obj \
./led.obj \
./main_tirtos.obj \
./nvs.obj \
./ti_printf.obj \
./uartecho.obj \
./syscfg/ti_devices_config.obj \
./syscfg/ti_drivers_config.obj 

GEN_MISC_FILES += \
./syscfg/ti_drivers_config.h \
./syscfg/ti_utils_build_linker.cmd.genlibs \
./syscfg/syscfg_c.rov.xs \
./syscfg/ti_utils_runtime_model.gv \
./syscfg/ti_utils_runtime_Makefile 

GEN_MISC_DIRS__QUOTED += \
"syscfg\" 

OBJS__QUOTED += \
"events.obj" \
"led.obj" \
"main_tirtos.obj" \
"nvs.obj" \
"ti_printf.obj" \
"uartecho.obj" \
"syscfg\ti_devices_config.obj" \
"syscfg\ti_drivers_config.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\ti_drivers_config.h" \
"syscfg\ti_utils_build_linker.cmd.genlibs" \
"syscfg\syscfg_c.rov.xs" \
"syscfg\ti_utils_runtime_model.gv" \
"syscfg\ti_utils_runtime_Makefile" 

C_DEPS__QUOTED += \
"events.d" \
"led.d" \
"main_tirtos.d" \
"nvs.d" \
"ti_printf.d" \
"uartecho.d" \
"syscfg\ti_devices_config.d" \
"syscfg\ti_drivers_config.d" 

GEN_FILES__QUOTED += \
"syscfg\ti_devices_config.c" \
"syscfg\ti_drivers_config.c" 

C_SRCS__QUOTED += \
"../events.c" \
"../led.c" \
"../main_tirtos.c" \
"../nvs.c" \
"../ti_printf.c" \
"../uartecho.c" \
"./syscfg/ti_devices_config.c" \
"./syscfg/ti_drivers_config.c" 

SYSCFG_SRCS__QUOTED += \
"../uartecho.syscfg" 


