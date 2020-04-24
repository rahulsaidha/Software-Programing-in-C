CC=g++
CFLAGS=-std=c++17

INCLUDEHEADER=-I ../../../include

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)

#TARGET TO COMPILE EVERYTHING
all: simulator run clean

#TARGET TO COMPILE ALL THE TESTS TOGETHER
main.o:
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) main.c -o build/main.o

brake_actuator.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../../src/System/brake_actuator.c -o build/brake_actuator.o

#TARGET TO COMPILE
simulator: main.o brake_actuator.o
	$(CC) -g -o test.exe build/main.o build/brake_actuator.o

#RUN
run:
	./test.exe

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/*