CC=g++
CFLAGS=-std=c++17

INCLUDEHEADER=-I ../../../include

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)

#TARGET TO COMPILE EVERYTHING
all: simulator run clean

main.o:
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) main.c -o build/main.o

controller.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../../src/System/controller.c -o build/controller.o
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../../src/System/bus_controller.c -o build/bus_controller.o

#TARGET TO COMPILE
simulator: main.o controller.o
	$(CC) -g -o test.exe build/main.o build/controller.o build/bus_controller.o

#RUN
run:
	./test.exe

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/*