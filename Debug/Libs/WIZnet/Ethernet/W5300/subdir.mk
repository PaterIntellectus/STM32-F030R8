################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/WIZnet/Ethernet/W5300/w5300.c 

OBJS += \
./Libs/WIZnet/Ethernet/W5300/w5300.o 

C_DEPS += \
./Libs/WIZnet/Ethernet/W5300/w5300.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/WIZnet/Ethernet/W5300/%.o Libs/WIZnet/Ethernet/W5300/%.su: ../Libs/WIZnet/Ethernet/W5300/%.c Libs/WIZnet/Ethernet/W5300/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Repositories/STM32-F030R8/Libs/WIZnet/Internet/DHCP" -I"D:/Repositories/STM32-F030R8/Libs/WIZnet/Ethernet" -I"D:/Repositories/STM32-F030R8/Libs/WIZnet/Internet/DNS" -I"D:/Repositories/STM32-F030R8/Libs/WIZnet/Ethernet/W5500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-WIZnet-2f-Ethernet-2f-W5300

clean-Libs-2f-WIZnet-2f-Ethernet-2f-W5300:
	-$(RM) ./Libs/WIZnet/Ethernet/W5300/w5300.d ./Libs/WIZnet/Ethernet/W5300/w5300.o ./Libs/WIZnet/Ethernet/W5300/w5300.su

.PHONY: clean-Libs-2f-WIZnet-2f-Ethernet-2f-W5300

