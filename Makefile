TARGETS=main

LOC=libs/*.c AMS_Test/*.c
DIRS=libs AMS_Test
INC_PARAMS=$(foreach d, $(DIRS), -I$d)
INC_DIRS=$(foreach d, $(DIRS), -L$d)



FLAGS=-mmcu=atmega32u4 -Os -DF_CPU=8000000UL -std=gnu99 -Wall
LIBS=-Wl,-u,vfprintf -lprintf_flt -lm

main: main.c
	avr-gcc $@.c $(LOC) $(FLAGS) $(INC_PARAMS) $(INC_DIRS) $(LIBS) -o $@.o
	avr-objcopy -O ihex $@.o $@.hex 	
build:
	avr-gcc $@.c libs/*.c $(FLAGS) $(INC_PARAMS) $(INC_DIRS) $(LIBS) -o $@.o
	avr-objcopy -O ihex $@.o $@.hex 
	teensy_loader_cli -mmcu=atmega32u4 -w @.hex
clean:
	rm *.o
	rm *.hex

rebuild: clean all

all: $(TARGETS)