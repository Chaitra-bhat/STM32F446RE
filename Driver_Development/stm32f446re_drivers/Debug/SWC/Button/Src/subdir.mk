################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SWC/Button/Src/button_interrupt.c \
../SWC/Button/Src/button_press.c 

OBJS += \
./SWC/Button/Src/button_interrupt.o \
./SWC/Button/Src/button_press.o 

C_DEPS += \
./SWC/Button/Src/button_interrupt.d \
./SWC/Button/Src/button_press.d 


# Each subdirectory must supply rules for building sources it contributes
SWC/Button/Src/%.o SWC/Button/Src/%.su SWC/Button/Src/%.cyclo: ../SWC/Button/Src/%.c SWC/Button/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/Reset_and_Clocks/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/System_Conf/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/Interrupt_Conf/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/SWC/Button/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/SWC/LED/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/GPIO_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-SWC-2f-Button-2f-Src

clean-SWC-2f-Button-2f-Src:
	-$(RM) ./SWC/Button/Src/button_interrupt.cyclo ./SWC/Button/Src/button_interrupt.d ./SWC/Button/Src/button_interrupt.o ./SWC/Button/Src/button_interrupt.su ./SWC/Button/Src/button_press.cyclo ./SWC/Button/Src/button_press.d ./SWC/Button/Src/button_press.o ./SWC/Button/Src/button_press.su

.PHONY: clean-SWC-2f-Button-2f-Src

