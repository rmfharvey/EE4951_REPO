################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/hal/src/adc16/fsl_adc16_hal.c 

OBJS += \
./SDK/platform/hal/src/adc16/fsl_adc16_hal.o 

C_DEPS += \
./SDK/platform/hal/src/adc16/fsl_adc16_hal.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/hal/src/adc16/%.o: ../SDK/platform/hal/src/adc16/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MK22FN512VDC12" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/hal/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/hal/src/sim/MK22F51212" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/system/src/clock/MK22F51212" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/system/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/osa/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/CMSIS/Include" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/devices" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/devices/MK22F51212/include" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/devices/MK22F51212/startup" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/Generated_Code/SDK/platform/devices/MK22F51212/startup" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/Sources" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/Generated_Code" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/drivers/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/EE4951_MCU/ee4951_mcu/SDK/platform/composite/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


