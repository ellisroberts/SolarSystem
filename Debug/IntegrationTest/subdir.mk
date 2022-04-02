# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../IntegrationTest/eventtest.cpp 

CPP_DEPS += \
../IntegrationTest/eventtest.d 

OBJS += \
../IntegrationTest/eventtest.o 


# Each subdirectory must supply rules for building sources it contributes
IntegrationTest/%.o: ../IntegrationTest/%.cpp IntegrationTest/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-IntegrationTest

clean-IntegrationTest:
	-$(RM) ./IntegrationTest/eventtest.d ./IntegrationTest/eventtest.o

.PHONY: clean-IntegrationTest