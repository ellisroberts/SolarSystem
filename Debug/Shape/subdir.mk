# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Shape/body.cpp 

OBJ_SRCS += \
../Shape/sphere.obj 

CPP_DEPS += \
./Shape/body.d 

OBJS += \
./Shape/body.o 


# Each subdirectory must supply rules for building sources it contributes
Shape/%.o: ../Shape/%.cpp Shape/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ $(CXXFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c "$<" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Shape

clean-Shape:
	-$(RM) ./Shape/body.d ./Shape/body.o

.PHONY: clean-Shape

