################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../JournalTesteur.cpp \
../OuvrageTesteur.cpp \
../ReferenceTesteur.cpp 

OBJS += \
./JournalTesteur.o \
./OuvrageTesteur.o \
./ReferenceTesteur.o 

CPP_DEPS += \
./JournalTesteur.d \
./OuvrageTesteur.d \
./ReferenceTesteur.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/vincebro/Documents/cpp/TP3/Classes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


