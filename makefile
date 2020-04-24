CC=g++
CFLAGS=-std=c++17

INCLUDEHEADER=-I include

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)

#TARGET TO COMPILE EVERYTHING AND CLEAN
all: compile clean

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

Simulator: main.o differential_time.o vehicle_angle.o vehicle_velocity.o position_integration.o driver_attitude.o information_display.o
	$(CC) -g -o Sim.exe build/main.o build/differential_time.o build/vehicle_angle.o build/vehicle_velocity.o build/position_integration.o build/driver_attitude.o build/information_display.o

System: main.o controller.o gas_pedal_sensor.o brake_pedal_sensor.o steering_wheel_sensor.o wheel_sensor.o direction_actuator.o fuel_actuator.o brake_actuator.o
	$(CC) -g -o Sim.exe build/main.o build/controller.o build/bus_controller.o build/gas_pedal_sensor.o build/brake_pedal_sensor.o build/steering_wheel_sensor.o build/wheel_sensor.o build/direction_actuator.o build/fuel_actuator.o build/brake_actuator.o

#TARGET TO COMPILE ALL
compile: main.o differential_time.o vehicle_angle.o vehicle_velocity.o position_integration.o driver_attitude.o information_display.o controller.o gas_pedal_sensor.o brake_pedal_sensor.o steering_wheel_sensor.o wheel_sensor.o direction_actuator.o fuel_actuator.o brake_actuator.o
	$(CC) -g -o Sim.exe build/main.o build/differential_time.o build/vehicle_angle.o build/vehicle_velocity.o build/position_integration.o build/driver_attitude.o build/information_display.o build/controller.o build/bus_controller.o build/gas_pedal_sensor.o build/brake_pedal_sensor.o build/steering_wheel_sensor.o build/wheel_sensor.o build/direction_actuator.o build/fuel_actuator.o build/brake_actuator.o

#TARGET TO COMPILE AND RUN UNIT TESTS
unit:
#	(cd test/Simulator/differential_time && make) 
#	(cd test/Simulator/driver_attitude && make) 
#	(cd test/Simulator/information_display && make) 
#	(cd test/Simulator/position_integration && make) 
#	(cd test/Simulator/vehicle_angle && make) 
	(cd test/Simulator/vehicle_velocity && make) 
	#(cd test/Simulator/Simulator && make) 

#	(cd test/System/brake_actuator && make) 
#	(cd test/System/brake_pedal_sensor && make)
#	(cd test/System/bus_controller && make)
#	(cd test/System/controller && make)
#	(cd test/System/direction_actuator && make)
#	(cd test/System/fuel_actuator && make)
#	(cd test/System/gas_pedal_sensor && make)
#	(cd test/System/steering_wheel_sensor && make)
#	(cd test/System/wheel_sensor && make)
#	(cd test/System/System && make)

#RUN
run:
	./Sim.exe

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/*