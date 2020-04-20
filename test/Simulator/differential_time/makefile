CC=g++
CFLAGS=-std=c++17

INCLUDEHEADER=-I ../../../include

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)

#TARGET TO COMPILE EVERYTHING (ABP SIMULATOR + TESTS TOGETHER)
all: Simulator run clean

#TARGET TO COMPILE ALL THE TESTS TOGETHER (NOT SIMULATOR)
main.o:
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) main.c -o build/main.o
differential_time.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../../src/Simulator/differential_time.c -o build/differential_time.o

#TARGET TO COMPILE ONLY ABP SIMULATOR
Simulator: main.o differential_time.o
	$(CC) -g -o test.exe build/main.o build/differential_time.o

#RUN TEST
run:
	./test.exe

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/*