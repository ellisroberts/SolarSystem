# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Shader/shader.cpp 

CPP_DEPS += \
./Shader/shader.d 

OBJS += \
./Shader/shader.o 


# Each subdirectory must supply rules for building sources it contributes
Shader/%.o: ../Shader/%.cpp Shader/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ $(CXXFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c "$<" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Shader

clean-Shader:
	-$(RM) ./Shader/shader.d ./Shader/shader.o

.PHONY: clean-Shader

