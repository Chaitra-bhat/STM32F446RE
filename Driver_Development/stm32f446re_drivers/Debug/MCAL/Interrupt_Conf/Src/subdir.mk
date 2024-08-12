################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Interrupt_Conf/Src/Interrupt_Conf.c 

OBJS += \
./MCAL/Interrupt_Conf/Src/Interrupt_Conf.o 

C_DEPS += \
./MCAL/Interrupt_Conf/Src/Interrupt_Conf.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Interrupt_Conf/Src/%.o MCAL/Interrupt_Conf/Src/%.su MCAL/Interrupt_Conf/Src/%.cyclo: ../MCAL/Interrupt_Conf/Src/%.c MCAL/Interrupt_Conf/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/Reset_and_Clocks/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/System_Conf/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/Interrupt_Conf/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/SWC/Button/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/SWC/LED/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/GPIO_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-Interrupt_Conf-2f-Src

clean-MCAL-2f-Interrupt_Conf-2f-Src:
	-$(RM) ./MCAL/Interrupt_Conf/Src/Interrupt_Conf.cyclo ./MCAL/Interrupt_Conf/Src/Interrupt_Conf.d ./MCAL/Interrupt_Conf/Src/Interrupt_Conf.o ./MCAL/Interrupt_Conf/Src/Interrupt_Conf.su

.PHONY: clean-MCAL-2f-Interrupt_Conf-2f-Src

