################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Board/board.c \
../Sources/Board/gpio_pins.c \
../Sources/Board/pin_mux.c 

OBJS += \
./Sources/Board/board.o \
./Sources/Board/gpio_pins.o \
./Sources/Board/pin_mux.o 

C_DEPS += \
./Sources/Board/board.d \
./Sources/Board/gpio_pins.d \
./Sources/Board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Board/%.o: ../Sources/Board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MK22FN512VDC12" -I"../Sources" -I"C:\Freescale\KSDK_1.3.0\platform\drivers\inc" -I"C:\Freescale\KSDK_1.3.0\platform\system\inc" -I"C:\Freescale\KSDK_1.3.0\platform\hal\inc" -I"C:\Freescale\KSDK_1.3.0\platform\osa\inc" -I"../Sources/Board" -I"../Sources/Utilities" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MK22F51212/include" -I"C:\Freescale\KSDK_1.3.0/platform/utilities/inc" -I"C:\Freescale\KSDK_1.3.0/platform/utilities/src" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


