CC=g++
CFLAGS=-std=c++17

INCLUDEHEADER=-I ../../../include

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)

#TARGET TO COMPILE EVERYTHING (ABP SIMULATOR + TESTS TOGETHER)
all: simulator run clean

#TARGET TO COMPILE ALL THE TESTS TOGETHER (NOT SIMULATOR)
main.o:
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) main.c -o build/main.o

brake_pedal_sensor.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../../src/System/brake_pedal_sensor.c -o build/brake_pedal_sensor.o

#TARGET TO COMPILE ONLY ABP SIMULATOR
simulator: main.o brake_pedal_sensor.o
	$(CC) -g -o test.exe build/main.o build/brake_pedal_sensor.o

#RUN
run:
	./test.exe

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/*