################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Server/RemoteServer.cpp \
../Server/Server.cpp 

OBJS += \
./Server/RemoteServer.o \
./Server/Server.o 

CPP_DEPS += \
./Server/RemoteServer.d \
./Server/Server.d 


# Each subdirectory must supply rules for building sources it contributes
Server/%.o: ../Server/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


