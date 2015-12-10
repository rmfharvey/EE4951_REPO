################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/hal/src/osc/fsl_osc_hal.c 

OBJS += \
./SDK/platform/hal/src/osc/fsl_osc_hal.o 

C_DEPS += \
./SDK/platform/hal/src/osc/fsl_osc_hal.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/hal/src/osc/%.o: ../SDK/platform/hal/src/osc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_RTOS_MQX" -D"PEX_MQX_KSDK" -D"CPU_MK22FN512VLL12" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/hal/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/hal/src/sim/MK22F51212" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/system/src/clock/MK22F51212" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/system/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/osa/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/CMSIS/Include" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/devices" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/devices/MK22F51212/include" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/utilities/src" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/utilities/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/devices/MK22F51212/startup" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/Generated_Code/SDK/platform/devices/MK22F51212/startup" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/Sources" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/Generated_Code" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/rtos/mqx/mqx/source/psp/cortex_m" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/rtos/mqx/mqx/source/psp/cortex_m/cpu" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/rtos/mqx/config/common" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/rtos/mqx/mqx/source/include" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/rtos/mqx/mqx/source/bsp" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/rtos/mqx/mqx/source/psp/cortex_m/compiler/gcc_arm" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/Generated_Code/SDK/rtos/mqx/config/board" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/Generated_Code/SDK/rtos/mqx/config/mcu" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/drivers/inc" -I"C:/Users/RossHarvey/Documents/School/EE4951_REPO/Firmware/MQXTest/mqxTest/SDK/platform/composite/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


