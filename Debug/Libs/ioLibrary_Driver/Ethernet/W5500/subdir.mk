################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/ioLibrary_Driver/Ethernet/W5500/w5500.c 

OBJS += \
./Libs/ioLibrary_Driver/Ethernet/W5500/w5500.o 

C_DEPS += \
./Libs/ioLibrary_Driver/Ethernet/W5500/w5500.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/ioLibrary_Driver/Ethernet/W5500/%.o Libs/ioLibrary_Driver/Ethernet/W5500/%.su: ../Libs/ioLibrary_Driver/Ethernet/W5500/%.c Libs/ioLibrary_Driver/Ethernet/W5500/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Repositories/STM32-F030R8/Libs/ioLibrary_Driver/Internet/DHCP" -I"D:/Repositories/STM32-F030R8/Libs/ioLibrary_Driver/Ethernet" -I"D:/Repositories/STM32-F030R8/Libs/ioLibrary_Driver/Internet/DNS" -I"D:/Repositories/STM32-F030R8/Libs/Pater Intellectus/WIZnet HTTP Client" -I"D:/Repositories/STM32-F030R8/Libs/Pater Intellectus/WIZnet Extension" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-ioLibrary_Driver-2f-Ethernet-2f-W5500

clean-Libs-2f-ioLibrary_Driver-2f-Ethernet-2f-W5500:
	-$(RM) ./Libs/ioLibrary_Driver/Ethernet/W5500/w5500.d ./Libs/ioLibrary_Driver/Ethernet/W5500/w5500.o ./Libs/ioLibrary_Driver/Ethernet/W5500/w5500.su

.PHONY: clean-Libs-2f-ioLibrary_Driver-2f-Ethernet-2f-W5500

