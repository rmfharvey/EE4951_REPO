################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/drivers/src/uart/fsl_uart_common.c \
../SDK/platform/drivers/src/uart/fsl_uart_driver.c 

OBJS += \
./SDK/platform/drivers/src/uart/fsl_uart_common.o \
./SDK/platform/drivers/src/uart/fsl_uart_driver.o 

C_DEPS += \
./SDK/platform/drivers/src/uart/fsl_uart_common.d \
./SDK/platform/drivers/src/uart/fsl_uart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/uart/%.o: ../SDK/platform/drivers/src/uart/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MK22FN512VDC12" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/hal/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/hal/src/sim/MK22F51212" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/system/src/clock/MK22F51212" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/system/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/osa/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/CMSIS/Include" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/devices" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/devices/MK22F51212/include" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/devices/MK22F51212/startup" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/Generated_Code/SDK/platform/devices/MK22F51212/startup" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/Sources" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/Generated_Code" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/drivers/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/composite/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


