################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX/Module/Src/taskManagerOthers.c 

CPP_SRCS += \
C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX/Module/Src/GraphicItemsExt.cpp \
C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX/Module/Src/ObjectData.cpp \
C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX/Module/Src/graphic_ext.cpp 

C_DEPS += \
./ADDITIONAL/GFX/Module/Src/taskManagerOthers.d 

OBJS += \
./ADDITIONAL/GFX/Module/Src/GraphicItemsExt.o \
./ADDITIONAL/GFX/Module/Src/ObjectData.o \
./ADDITIONAL/GFX/Module/Src/graphic_ext.o \
./ADDITIONAL/GFX/Module/Src/taskManagerOthers.o 

CPP_DEPS += \
./ADDITIONAL/GFX/Module/Src/GraphicItemsExt.d \
./ADDITIONAL/GFX/Module/Src/ObjectData.d \
./ADDITIONAL/GFX/Module/Src/graphic_ext.d 


# Each subdirectory must supply rules for building sources it contributes
ADDITIONAL/GFX/Module/Src/GraphicItemsExt.o: C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX/Module/Src/GraphicItemsExt.cpp ADDITIONAL/GFX/Module/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Middlewares/ST/touchgfx/framework/include -I"C:/ATProgetti/Px4/Middlewares/ST/touchgfx/framework/include" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/include" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/CMSIS_RTOS" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/GFX" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/CMSIS/Include" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Host_Library/Core/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Device_Library/Core/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Host_Library/Class/MSC/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/ATProgetti/PG064/PG/SRC/STARTUP" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/LwIP" -I"C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL" -I"C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX" -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fexceptions -fstack-usage -MMD -MP -MF"ADDITIONAL/GFX/Module/Src/GraphicItemsExt.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
ADDITIONAL/GFX/Module/Src/ObjectData.o: C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX/Module/Src/ObjectData.cpp ADDITIONAL/GFX/Module/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Middlewares/ST/touchgfx/framework/include -I"C:/ATProgetti/Px4/Middlewares/ST/touchgfx/framework/include" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/include" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/CMSIS_RTOS" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/GFX" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/CMSIS/Include" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Host_Library/Core/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Device_Library/Core/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Host_Library/Class/MSC/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/ATProgetti/PG064/PG/SRC/STARTUP" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/LwIP" -I"C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL" -I"C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX" -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fexceptions -fstack-usage -MMD -MP -MF"ADDITIONAL/GFX/Module/Src/ObjectData.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
ADDITIONAL/GFX/Module/Src/graphic_ext.o: C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX/Module/Src/graphic_ext.cpp ADDITIONAL/GFX/Module/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Middlewares/ST/touchgfx/framework/include -I"C:/ATProgetti/Px4/Middlewares/ST/touchgfx/framework/include" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/include" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/CMSIS_RTOS" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/GFX" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/CMSIS/Include" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Host_Library/Core/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Device_Library/Core/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Host_Library/Class/MSC/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/ATProgetti/PG064/PG/SRC/STARTUP" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/LwIP" -I"C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL" -I"C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX" -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fexceptions -fstack-usage -MMD -MP -MF"ADDITIONAL/GFX/Module/Src/graphic_ext.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
ADDITIONAL/GFX/Module/Src/taskManagerOthers.o: C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX/Module/Src/taskManagerOthers.c ADDITIONAL/GFX/Module/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Middlewares/ST/touchgfx/framework/include -I"C:/ATProgetti/Px4/Middlewares/ST/touchgfx/framework/include" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/include" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/CMSIS_RTOS" -I"C:/ATProgetti/PG064/PG/SRC/OS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/GFX" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/CMSIS/Include" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Device_Library/Core/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Host_Library/Core/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Host_Library/Class/MSC/Inc" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/USB/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/ATProgetti/PG064/PG/SRC/STARTUP" -I"C:/ATProgetti/PG064/PG/SRC/APPLICAZIONE/Libraries/LwIP" -I"C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL" -I"C:/ATProgetti/PG0XX/PG/SRC/ADDITIONAL/GFX" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"ADDITIONAL/GFX/Module/Src/taskManagerOthers.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

