################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/WIZnet/Internet/DNS/dns.c 

OBJS += \
./Libs/WIZnet/Internet/DNS/dns.o 

C_DEPS += \
./Libs/WIZnet/Internet/DNS/dns.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/WIZnet/Internet/DNS/%.o Libs/WIZnet/Internet/DNS/%.su: ../Libs/WIZnet/Internet/DNS/%.c Libs/WIZnet/Internet/DNS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Repositories/STM32-F030R8/Libs/WIZnet/Internet/DHCP" -I"D:/Repositories/STM32-F030R8/Libs/WIZnet/Ethernet" -I"D:/Repositories/STM32-F030R8/Libs/WIZnet/Internet/DNS" -I"D:/Repositories/STM32-F030R8/Libs/WIZnet/Ethernet/W5500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-WIZnet-2f-Internet-2f-DNS

clean-Libs-2f-WIZnet-2f-Internet-2f-DNS:
	-$(RM) ./Libs/WIZnet/Internet/DNS/dns.d ./Libs/WIZnet/Internet/DNS/dns.o ./Libs/WIZnet/Internet/DNS/dns.su

.PHONY: clean-Libs-2f-WIZnet-2f-Internet-2f-DNS

