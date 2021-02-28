################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AllTests.c \
../CuTest.c \
../Question1.c \
../Question2.c \
../Question3.c \
../testCases.c 

OBJS += \
./AllTests.o \
./CuTest.o \
./Question1.o \
./Question2.o \
./Question3.o \
./testCases.o 

C_DEPS += \
./AllTests.d \
./CuTest.d \
./Question1.d \
./Question2.d \
./Question3.d \
./testCases.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


