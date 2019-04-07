################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Bibliographie.cpp \
../src/ContratException.cpp \
../src/Journal.cpp \
../src/Ouvrage.cpp \
../src/Reference.cpp \
../src/Util.cpp 

OBJS += \
./src/Bibliographie.o \
./src/ContratException.o \
./src/Journal.o \
./src/Ouvrage.o \
./src/Reference.o \
./src/Util.o 

CPP_DEPS += \
./src/Bibliographie.d \
./src/ContratException.d \
./src/Journal.d \
./src/Ouvrage.d \
./src/Reference.d \
./src/Util.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


