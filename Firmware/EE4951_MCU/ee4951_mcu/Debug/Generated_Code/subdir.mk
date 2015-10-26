################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/DUT_ADC.c \
../Generated_Code/PORTC.c \
../Generated_Code/PORTE.c \
../Generated_Code/SD_CARD.c \
../Generated_Code/SELF_ADC.c \
../Generated_Code/SPI1.c \
../Generated_Code/clockMan1.c \
../Generated_Code/fsl_dspi1.c \
../Generated_Code/hardware_init.c \
../Generated_Code/osa1.c \
../Generated_Code/pin_mux.c \
../Generated_Code/uartCom1.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/DUT_ADC.o \
./Generated_Code/PORTC.o \
./Generated_Code/PORTE.o \
./Generated_Code/SD_CARD.o \
./Generated_Code/SELF_ADC.o \
./Generated_Code/SPI1.o \
./Generated_Code/clockMan1.o \
./Generated_Code/fsl_dspi1.o \
./Generated_Code/hardware_init.o \
./Generated_Code/osa1.o \
./Generated_Code/pin_mux.o \
./Generated_Code/uartCom1.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/DUT_ADC.d \
./Generated_Code/PORTC.d \
./Generated_Code/PORTE.d \
./Generated_Code/SD_CARD.d \
./Generated_Code/SELF_ADC.d \
./Generated_Code/SPI1.d \
./Generated_Code/clockMan1.d \
./Generated_Code/fsl_dspi1.d \
./Generated_Code/hardware_init.d \
./Generated_Code/osa1.d \
./Generated_Code/pin_mux.d \
./Generated_Code/uartCom1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MK22FN512VDC12" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/hal/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/hal/src/sim/MK22F51212" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/system/src/clock/MK22F51212" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/system/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/osa/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/CMSIS/Include" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/devices" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/devices/MK22F51212/include" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/devices/MK22F51212/startup" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/Generated_Code/SDK/platform/devices/MK22F51212/startup" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/Sources" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/Generated_Code" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/drivers/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/composite/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


