################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SWC/LED/Src/Led_toggle.c 

OBJS += \
./SWC/LED/Src/Led_toggle.o 

C_DEPS += \
./SWC/LED/Src/Led_toggle.d 


# Each subdirectory must supply rules for building sources it contributes
SWC/LED/Src/%.o SWC/LED/Src/%.su SWC/LED/Src/%.cyclo: ../SWC/LED/Src/%.c SWC/LED/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/Reset_and_Clocks/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/System_Conf/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/Interrupt_Conf/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/SWC/Button/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/SWC/LED/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/Inc" -I"C:/Users/Chait/OneDrive/Projects/Driver_Development/stm32f446re_drivers/MCAL/GPIO_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-SWC-2f-LED-2f-Src

clean-SWC-2f-LED-2f-Src:
	-$(RM) ./SWC/LED/Src/Led_toggle.cyclo ./SWC/LED/Src/Led_toggle.d ./SWC/LED/Src/Led_toggle.o ./SWC/LED/Src/Led_toggle.su

.PHONY: clean-SWC-2f-LED-2f-Src

