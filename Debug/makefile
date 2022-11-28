################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Libs/ioLibrary_Driver/Ethernet/W5500/subdir.mk
-include Libs/ioLibrary_Driver/Ethernet/W5300/subdir.mk
-include Libs/ioLibrary_Driver/Ethernet/W5200/subdir.mk
-include Libs/ioLibrary_Driver/Ethernet/W5100S/subdir.mk
-include Libs/ioLibrary_Driver/Ethernet/W5100/subdir.mk
-include Libs/ioLibrary_Driver/Ethernet/subdir.mk
-include Libs/Pater\ Intellectus/WIZnet\ HTTP\ Client/subdir.mk
-include Libs/Pater\ Intellectus/WIZnet\ Extension/subdir.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := cortex-m0_project
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
cortex-m0_project.elf \

MAP_FILES += \
cortex-m0_project.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
cortex-m0_project.list \

OBJCOPY_HEX += \
cortex-m0_project.hex \

OBJCOPY_BIN += \
cortex-m0_project.bin \


# All Target
all: main-build

# Main-build Target
main-build: cortex-m0_project.elf secondary-outputs

# Tool invocations
cortex-m0_project.elf cortex-m0_project.map: $(OBJS) $(USER_OBJS) D:\Repositories\STM32-F030R8\STM32F030R8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "cortex-m0_project.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"D:\Repositories\STM32-F030R8\STM32F030R8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="cortex-m0_project.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

cortex-m0_project.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "cortex-m0_project.list"
	@echo 'Finished building: $@'
	@echo ' '

cortex-m0_project.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "cortex-m0_project.hex"
	@echo 'Finished building: $@'
	@echo ' '

cortex-m0_project.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "cortex-m0_project.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) cortex-m0_project.bin cortex-m0_project.elf cortex-m0_project.hex cortex-m0_project.list cortex-m0_project.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
