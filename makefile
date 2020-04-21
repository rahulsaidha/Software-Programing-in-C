CC=g++
CFLAGS=-std=c++17

INCLUDEHEADER=-I include

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)

#TARGET TO COMPILE EVERYTHING (ABP SIMULATOR + TESTS TOGETHER)
all: alltogether clean

#TARGET TO COMPILE ALL THE TESTS TOGETHER (NOT SIMULATOR)
main.o:
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/main.c -o build/main.o
differential_time.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/Simulator/differential_time.c -o build/differential_time.o
vehicle_angle.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/Simulator/vehicle_angle.c -o build/vehicle_angle.o
vehicle_velocity.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/Simulator/vehicle_velocity.c -o build/vehicle_velocity.o
position_integration.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/Simulator/position_integration.c -o build/position_integration.o
driver_attitude.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/Simulator/driver_attitude.c -o build/driver_attitude.o
information_display.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/Simulator/information_display.c -o build/information_display.o

controller.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/System/controller.c -o build/controller.o
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/System/bus_controller.c -o build/bus_controller.o
gas_pedal_sensor.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/System/gas_pedal_sensor.c -o build/gas_pedal_sensor.o
brake_pedal_sensor.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/System/brake_pedal_sensor.c -o build/brake_pedal_sensor.o
steering_wheel_sensor.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/System/steering_wheel_sensor.c -o build/steering_wheel_sensor.o
wheel_sensor.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/System/wheel_sensor.c -o build/wheel_sensor.o
direction_actuator.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/System/direction_actuator.c -o build/direction_actuator.o
fuel_actuator.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/System/fuel_actuator.c -o build/fuel_actuator.o
brake_actuator.o: 
	$(CC) -g -c $(CFLAGS) $(INCLUDEHEADER) src/System/brake_actuator.c -o build/brake_actuator.o

#TARGET TO COMPILE ONLY ABP SIMULATOR
Simulator: main.o differential_time.o vehicle_angle.o vehicle_velocity.o position_integration.o driver_attitude.o information_display.o
	$(CC) -g -o test.exe build/main.o build/differential_time.o build/vehicle_angle.o build/vehicle_velocity.o build/position_integration.o build/driver_attitude.o build/information_display.o

#TARGET TO COMPILE ONLY ABP SIMULATOR
System: main.o controller.o gas_pedal_sensor.o brake_pedal_sensor.o steering_wheel_sensor.o wheel_sensor.o direction_actuator.o fuel_actuator.o brake_actuator.o
	$(CC) -g -o test.exe build/main.o build/controller.o build/bus_controller.o build/gas_pedal_sensor.o build/brake_pedal_sensor.o build/steering_wheel_sensor.o build/wheel_sensor.o build/direction_actuator.o build/fuel_actuator.o build/brake_actuator.o

#TARGET TO COMPILE ALL
alltogether: main.o differential_time.o vehicle_angle.o vehicle_velocity.o position_integration.o driver_attitude.o information_display.o controller.o gas_pedal_sensor.o brake_pedal_sensor.o steering_wheel_sensor.o wheel_sensor.o direction_actuator.o fuel_actuator.o brake_actuator.o
	$(CC) -g -o test.exe build/main.o build/differential_time.o build/vehicle_angle.o build/vehicle_velocity.o build/position_integration.o build/driver_attitude.o build/information_display.o build/controller.o build/bus_controller.o build/gas_pedal_sensor.o build/brake_pedal_sensor.o build/steering_wheel_sensor.o build/wheel_sensor.o build/direction_actuator.o build/fuel_actuator.o build/brake_actuator.o

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/*