# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PlanetManager/planetmanager.cpp 

CPP_DEPS += \
./PlanetManager/planetmanager.d 

OBJS += \
./PlanetManager/planetmanager.o 


# Each subdirectory must supply rules for building sources it contributes
PlanetManager/%.o: ../PlanetManager/%.cpp PlanetManager/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-PlanetManager

clean-PlanetManager:
	-$(RM) ./PlanetManager/planetmanager.d ./PlanetManager/planetmanager.o

.PHONY: clean-PlanetManager

