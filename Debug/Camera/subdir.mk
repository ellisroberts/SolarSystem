# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Camera/camera.cpp 

CPP_DEPS += \
./Camera/camera.d 

OBJS += \
./Camera/camera.o 


# Each subdirectory must supply rules for building sources it contributes
Camera/%.o: ../Camera/%.cpp Camera/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ $(CXXFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c "$<" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Camera

clean-Camera:
	-$(RM) ./Camera/camera.d ./Camera/camera.o

.PHONY: clean-Camera

