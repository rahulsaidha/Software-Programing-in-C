#include "header.h"
#include <string.h>

void wheel_sensor(struct VEHICLE_STATUS *vehicle_status);

int main(){
    // Define Variables
	VEHICLE_STATUS *vehicle;
    vehicle = (struct VEHICLE_STATUS*) malloc(sizeof(struct VEHICLE_STATUS));

    // Open file
    FILE *fp;
    char str[100];
    char* filename = "log.txt";
    fp = fopen(filename, "w");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    // Run testcase
    vehicle->vehicle_wheel_angle = 1;
    vehicle->vehicle_wheel_rotation = 2;
    vehicle->vehicle_position_X = 3;
    vehicle->vehicle_position_Y = 4;
    vehicle->motor_rotation = 5;
    vehicle->gas_pedal_pos = 6;
    vehicle->brake_pedal_pos = 7;
    vehicle->steering_wheel_pos = 8;
    vehicle->direction_actuator_pos = 9;
    vehicle->fuel_actuator_pos = 10;
    vehicle->brake_actuator_pos = 11;
    
    double message;

    //Testcase 0: requesting another device
    message = 0;
    vehicle->Comm_bus_address = GAS_PEDAL_SSR_ADDRESS;
    wheel_sensor(vehicle);
    fprintf(fp,"\nTestcase 0\n");
    fprintf(fp,"Expected: %d | Result: %d\n", GAS_PEDAL_SSR_ADDRESS, vehicle->Comm_bus_address);
    fprintf(fp,"Expected: %f | Result: %f\n", message, vehicle->Comm_bus_message);

    //Testcase 1: requesting and receiving from device
    vehicle->Comm_bus_address = WHEEL_SSR_ADDRESS;
    wheel_sensor(vehicle);
    fprintf(fp,"\nTestcase 1\n");
    fprintf(fp,"Expected: %d | Result: %d\n", CTRL_ADDRESS, vehicle->Comm_bus_address);
    fprintf(fp,"Expected: %f | Result: %f\n", vehicle->vehicle_wheel_rotation, vehicle->Comm_bus_message);

    //Testcase 2: requesting again with another value
    vehicle->vehicle_wheel_rotation = 10;
    vehicle->Comm_bus_address = WHEEL_SSR_ADDRESS;
    wheel_sensor(vehicle);
    fprintf(fp,"\nTestcase 2\n");
    fprintf(fp,"Expected: %d | Result: %d\n", CTRL_ADDRESS, vehicle->Comm_bus_address);
    fprintf(fp,"Expected: %f | Result: %f\n", vehicle->vehicle_wheel_rotation, vehicle->Comm_bus_message);

	printf("Press any key to finish\n");
	getchar();
    fclose(fp);
}