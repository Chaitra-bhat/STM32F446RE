################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Reset_and_Clocks/Src/stm32f446re_rcc.c 

OBJS += \
./MCAL/Reset_and_Clocks/Src/stm32f446re_rcc.o 

C_DEPS += \
./MCAL/Reset_and_Clocks/Src/stm32f446re_rcc.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Reset_and_Clocks/Src/%.o MCAL/Reset_and_Clocks/Src/%.su MCAL/Reset_and_Clocks/Src/%.cyclo: ../MCAL/Reset_and_Clocks/Src/%.c MCAL/Reset_and_Clocks/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/Reset_and_Clocks/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/System_Conf/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/Interrupt_Conf/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/SWC/Button/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/SWC/LED/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/GPIO_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-Reset_and_Clocks-2f-Src

clean-MCAL-2f-Reset_and_Clocks-2f-Src:
	-$(RM) ./MCAL/Reset_and_Clocks/Src/stm32f446re_rcc.cyclo ./MCAL/Reset_and_Clocks/Src/stm32f446re_rcc.d ./MCAL/Reset_and_Clocks/Src/stm32f446re_rcc.o ./MCAL/Reset_and_Clocks/Src/stm32f446re_rcc.su

.PHONY: clean-MCAL-2f-Reset_and_Clocks-2f-Src

