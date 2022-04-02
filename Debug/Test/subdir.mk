# Add inputs and outputs from these tool invocations to the build variables 
-include ../objects.mk

TEST_CPP_DEPS = \
./Test/bodytest.d \
./Test/cameratest.d \
./Test/planetmanagertest.d \
./Test/rendertest.d \
./Test/main.d

-include $(TEST_CPP_DEPS)

TEST_OBJS = \
./Test/bodytest.o \
../Shape/body.o \
./Test/cameratest.o \
../Camera/camera.o \
./Test/planetmanagertest.o  \
../PlanetManager/planetmanager.o \
./Test/rendertest.o \
../Render/objectload.o \
./Test/main.o

Test/TestBench : $(TEST_OBJS) Test/subdir.mk
	@echo 'Building Test Bench'
	@echo $(TESTOBJS)
	g++ $(CXXFLAGS) $(CPPFLAGS) $(TEST_OBJS) $(LIBS) -o "$@"
	@echo 'Finished building $@'

# Each subdirectory must supply rules for building sources it contributes
Test/%.o: ../Test/%.cpp Test/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ $(CXXFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c "$<" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Test

clean-Test:
	-$(RM) ./Test/bodytest.d ./Test/bodytest.o ./Test/cameratest.d ./Test/cameratest.o ./Test/planetmanagertest.o /Test/rendertest.d ./Test/rendertest.o ./Test/main.d ./Test/main.o

.PHONY: clean-Test

