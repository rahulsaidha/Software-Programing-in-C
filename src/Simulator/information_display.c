#include "header.h"

void information_display(double time, struct VEHICLE_STATUS* vehicle){
	fseek(stdout, 0 , SEEK_SET);
	printf("\e[1;1H\e[2J");

	printf("--------Vehicle Simulator-------\n");
	printf("________________________________\n");
	printf("Time: %f\n", time);
	printf("                                \n");
	printf("--------Vehicle Position--------\n");
	printf("________________________________\n");
	printf("Position in X: %0.2f\n", vehicle->vehicle_position_X);
	printf("Position in Y: %0.2f\n", vehicle->vehicle_position_Y);
	printf("                                \n");	
	printf("--------Vehicle Status----------\n");
	printf("________________________________\n");
	printf("Motor Rotation: 	    %0.2f\n", vehicle->motor_rotation);
	printf("Wheel Rotation: 	    %0.2f\n", vehicle->vehicle_wheel_rotation);
	printf("Gas Pedal Position: 	    %0.2f\n", vehicle->gas_pedal_pos);
	printf("Fuel Actuator Pos: 	    %0.2f\n", vehicle->fuel_actuator_pos);
	printf("Brake Pedal Position: 	    %0.2f\n", vehicle->brake_pedal_pos);
	printf("Brake Actuator Pos: 	    %0.2f\n", vehicle->brake_actuator_pos);
	printf("Steering Wheel Position:    %0.2f\n", vehicle->steering_wheel_pos);
	printf("Direction Actuator Pos:     %0.2f\n", vehicle->direction_actuator_pos);
	printf("Wheel Angle: 	            %0.2f\n", vehicle->vehicle_wheel_angle);
	printf("                                \n");
}