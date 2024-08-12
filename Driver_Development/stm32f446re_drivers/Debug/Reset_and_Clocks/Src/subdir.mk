################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Reset_and_Clocks/Src/stm32f446re_rcc.c 

OBJS += \
./Reset_and_Clocks/Src/stm32f446re_rcc.o 

C_DEPS += \
./Reset_and_Clocks/Src/stm32f446re_rcc.d 


# Each subdirectory must supply rules for building sources it contributes
Reset_and_Clocks/Src/%.o Reset_and_Clocks/Src/%.su Reset_and_Clocks/Src/%.cyclo: ../Reset_and_Clocks/Src/%.c Reset_and_Clocks/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/Reset_and_Clocks" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/memory_Drivers/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/GPIO_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Reset_and_Clocks-2f-Src

clean-Reset_and_Clocks-2f-Src:
	-$(RM) ./Reset_and_Clocks/Src/stm32f446re_rcc.cyclo ./Reset_and_Clocks/Src/stm32f446re_rcc.d ./Reset_and_Clocks/Src/stm32f446re_rcc.o ./Reset_and_Clocks/Src/stm32f446re_rcc.su

.PHONY: clean-Reset_and_Clocks-2f-Src

