################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Distance_Measure.lss \

FLASH_IMAGE += \
Distance_Measure.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Distance_Measure.elf secondary-outputs

# Tool invocations
Distance_Measure.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Distance_Measure.map -mmcu=atmega16 -o "Distance_Measure.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Distance_Measure.lss: Distance_Measure.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Distance_Measure.elf  >"Distance_Measure.lss"
	@echo 'Finished building: $@'
	@echo ' '

Distance_Measure.hex: Distance_Measure.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Distance_Measure.elf  "Distance_Measure.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Distance_Measure.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Distance_Measure.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Distance_Measure.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
