################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO_drivers/src/stm32f446re_gpio.c 

OBJS += \
./GPIO_drivers/src/stm32f446re_gpio.o 

C_DEPS += \
./GPIO_drivers/src/stm32f446re_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO_drivers/src/%.o GPIO_drivers/src/%.su GPIO_drivers/src/%.cyclo: ../GPIO_drivers/src/%.c GPIO_drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/Reset_and_Clocks/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/memory_Drivers/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/GPIO_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-GPIO_drivers-2f-src

clean-GPIO_drivers-2f-src:
	-$(RM) ./GPIO_drivers/src/stm32f446re_gpio.cyclo ./GPIO_drivers/src/stm32f446re_gpio.d ./GPIO_drivers/src/stm32f446re_gpio.o ./GPIO_drivers/src/stm32f446re_gpio.su

.PHONY: clean-GPIO_drivers-2f-src

