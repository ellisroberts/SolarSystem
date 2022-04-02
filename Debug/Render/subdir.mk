# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Render/objectload.cpp 

CPP_DEPS += \
./Render/objectload.d 

OBJS += \
./Render/objectload.o 


# Each subdirectory must supply rules for building sources it contributes
Render/%.o: ../Render/%.cpp Render/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ $(CXXFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c "$<" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Render

clean-Render:
	-$(RM) ./Render/objectload.d ./Render/objectload.o

.PHONY: clean-Render