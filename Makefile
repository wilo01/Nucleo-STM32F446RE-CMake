#Compiler

#TD=/usr/local/Caskroom/gcc-arm-embedded/7-2018-q2-update/gcc-arm-none-eabi-7-2018-q2-update/bin/
TD=/usr/bin
#CC=$(TD)/arm-none-eabi-gcc
#LD=$(TD)/arm-none-eabi-g++
CC=$(TD)/gcc
LD=$(TD)/g++

#Include files
INC = -Iinclude

#Compiler flags
CFLAGS = $(INC) -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -O0

#Linker flags
LFLAGS = -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -specs=nosys.specs -T STM32F446ZETx_FLASH.ld -Wl,--gc-sections -lm

#Linking
all: main.o startup_stm32f446xx.o 
	$(LD) $(LFLAGS)  output/main.o output/startup_stm32f446xx.o -o output/program.elf

#Compiling main.c
main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o output/main.o

#Compiling startup_stm32f429xx.s
startup_stm32f446xx.o: src/startup_stm32f446xx.s
	$(CC) $(CFLAGS) -c src/startup_stm32f446xx.s -o output/startup_stm32f446xx.o

#Cleaning
clean:
	rm -f output/program.elf output/*.o

