################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/Pater\ Intellectus/WIZnet\ HTTP\ Client/http_client.c 

OBJS += \
./Libs/Pater\ Intellectus/WIZnet\ HTTP\ Client/http_client.o 

C_DEPS += \
./Libs/Pater\ Intellectus/WIZnet\ HTTP\ Client/http_client.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/Pater\ Intellectus/WIZnet\ HTTP\ Client/http_client.o: ../Libs/Pater\ Intellectus/WIZnet\ HTTP\ Client/http_client.c Libs/Pater\ Intellectus/WIZnet\ HTTP\ Client/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Repositories/STM32-F030R8/Libs/ioLibrary_Driver/Internet/DHCP" -I"D:/Repositories/STM32-F030R8/Libs/ioLibrary_Driver/Ethernet" -I"D:/Repositories/STM32-F030R8/Libs/ioLibrary_Driver/Internet/DNS" -I"D:/Repositories/STM32-F030R8/Libs/Pater Intellectus/WIZnet HTTP Client" -I"D:/Repositories/STM32-F030R8/Libs/Pater Intellectus/WIZnet Extension" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Libs/Pater Intellectus/WIZnet HTTP Client/http_client.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-Pater-20-Intellectus-2f-WIZnet-20-HTTP-20-Client

clean-Libs-2f-Pater-20-Intellectus-2f-WIZnet-20-HTTP-20-Client:
	-$(RM) ./Libs/Pater\ Intellectus/WIZnet\ HTTP\ Client/http_client.d ./Libs/Pater\ Intellectus/WIZnet\ HTTP\ Client/http_client.o ./Libs/Pater\ Intellectus/WIZnet\ HTTP\ Client/http_client.su

.PHONY: clean-Libs-2f-Pater-20-Intellectus-2f-WIZnet-20-HTTP-20-Client

