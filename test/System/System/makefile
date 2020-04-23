CC=g++
CFLAGS=-std=c++17

INCLUDEHEADER=-I ../../include

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)

#TARGET TO COMPILE EVERYTHING (ABP SIMULATOR + TESTS TOGETHER)
all: System clean

#TARGET TO COMPILE ALL THE TESTS TOGETHER (NOT SIMULATOR)
main.o:
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) main.c -o build/main.o
controller.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../src/System/controller.c -o build/controller.o
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../src/System/bus_controller.c -o build/bus_controller.o
gas_pedal_sensor.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../src/System/gas_pedal_sensor.c -o build/gas_pedal_sensor.o
brake_pedal_sensor.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../src/System/brake_pedal_sensor.c -o build/brake_pedal_sensor.o
steering_wheel_sensor.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../src/System/steering_wheel_sensor.c -o build/steering_wheel_sensor.o
wheel_sensor.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../src/System/wheel_sensor.c -o build/wheel_sensor.o
direction_actuator.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../src/System/direction_actuator.c -o build/direction_actuator.o
fuel_actuator.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../src/System/fuel_actuator.c -o build/fuel_actuator.o
brake_actuator.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) ../../src/System/brake_actuator.c -o build/brake_actuator.o

#TARGET TO COMPILE ONLY ABP SIMULATOR
System: main.o controller.o gas_pedal_sensor.o brake_pedal_sensor.o steering_wheel_sensor.o wheel_sensor.o direction_actuator.o fuel_actuator.o brake_actuator.o
	$(CC) -g -o test.exe build/main.o build/controller.o build/bus_controller.o build/gas_pedal_sensor.o build/brake_pedal_sensor.o build/steering_wheel_sensor.o build/wheel_sensor.o build/direction_actuator.o build/fuel_actuator.o build/brake_actuator.o

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/*