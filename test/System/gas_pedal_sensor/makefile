CC=g++
CFLAGS=-std=c++17

INCLUDEHEADER=-I ../../../include

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)

#TARGET TO COMPILE EVERYTHING
all: simulator run clean

#TARGET TO COMPILE
main.o:
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) main.c -o build/main.o

gas_pedal_sensor.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../../src/System/gas_pedal_sensor.c -o build/gas_pedal_sensor.o

#TARGET TO COMPILE
simulator: main.o gas_pedal_sensor.o
	$(CC) -g -o test.exe build/main.o build/gas_pedal_sensor.o

#RUN
run:
	./test.exe

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/*