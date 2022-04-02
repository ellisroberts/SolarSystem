-include ../makefile.init

RM := rm -rf
CXXFLAGS = -std=c++11
CPPFLAGS = -O0 -g3 -Wall -fmessage-length=0
DEPFLAGS = -MMD -MP -MF"$(@:%.o=%.d)"

# All of the sources participating in the build are defined here
-include sources.mk
#-include Render/subdir.mk
#-include Shape/subdir.mk
#-include Shader/subdir.mk
-include IntegrationTest/subdir.mk
-include PlanetManager/subdir.mk
-include Camera/subdir.mk
-include Test/subdir.mk
#-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SolarSystem
BUILD_ARTIFACT_EXTENSION :=
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: SolarSystem

# Tool invocations
SolarSystem: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS) Test/TestBench
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	./Test/TestBench
	g++  -o "SolarSystem" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) SolarSystem
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
