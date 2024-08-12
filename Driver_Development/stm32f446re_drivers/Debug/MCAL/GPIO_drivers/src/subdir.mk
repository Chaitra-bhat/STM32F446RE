################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO_drivers/src/stm32f446re_gpio.c 

OBJS += \
./MCAL/GPIO_drivers/src/stm32f446re_gpio.o 

C_DEPS += \
./MCAL/GPIO_drivers/src/stm32f446re_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO_drivers/src/%.o MCAL/GPIO_drivers/src/%.su MCAL/GPIO_drivers/src/%.cyclo: ../MCAL/GPIO_drivers/src/%.c MCAL/GPIO_drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/Reset_and_Clocks/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/System_Conf/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/Interrupt_Conf/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/SWC/Button/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/SWC/LED/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/GPIO_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-GPIO_drivers-2f-src

clean-MCAL-2f-GPIO_drivers-2f-src:
	-$(RM) ./MCAL/GPIO_drivers/src/stm32f446re_gpio.cyclo ./MCAL/GPIO_drivers/src/stm32f446re_gpio.d ./MCAL/GPIO_drivers/src/stm32f446re_gpio.o ./MCAL/GPIO_drivers/src/stm32f446re_gpio.su

.PHONY: clean-MCAL-2f-GPIO_drivers-2f-src

