/*

*/
#include "header.h"
#include <string.h>

void direction_actuator(struct VEHICLE_STATUS *vehicle_status);

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
    vehicle->vehicle_wheel_angle = 1.0;
    vehicle->vehicle_wheel_rotation = 2.0;
    vehicle->vehicle_position_X = 3.0;
    vehicle->vehicle_position_Y = 4.0;
    vehicle->motor_rotation = 5.0;
    vehicle->gas_pedal_pos = 6.0;
    vehicle->brake_pedal_pos = 7.0;
    vehicle->steering_wheel_pos = 8.0;
    vehicle->direction_actuator_pos = 30;
    vehicle->fuel_actuator_pos = 30;
    vehicle->brake_actuator_pos = 30;
    
    double message;

    //Testcase 0: requesting another device
    message = 0;
    vehicle->Comm_bus_address = GAS_PEDAL_SSR_ADDRESS;
    vehicle->Comm_bus_message = 0;
    direction_actuator(vehicle);
    fprintf(fp,"\nTestcase 0\n");
    fprintf(fp,"Expected: %d | Result: %d\n", GAS_PEDAL_SSR_ADDRESS, vehicle->Comm_bus_address);
    fprintf(fp,"Expected: %f | Result: %f\n", message, vehicle->Comm_bus_message);

    //Testcase 1: requesting to device and receiving confirmation
    vehicle->Comm_bus_message = 9.0;
    vehicle->Comm_bus_address = DIR_ACT_ADDRESS;
    direction_actuator(vehicle);
    fprintf(fp,"\nTestcase 1\n");
    fprintf(fp,"Expected: %d | Result: %d\n", CTRL_ADDRESS, vehicle->Comm_bus_address);
    fprintf(fp,"Expected: %f | Result: %f\n", 9.0, vehicle->direction_actuator_pos);
    fprintf(fp,"Expected: %f | Result: %f\n", 1.0, vehicle->Comm_bus_message);

    //Testcase 2: requesting again with another value
    vehicle->Comm_bus_message = 12.0;
    vehicle->Comm_bus_address = DIR_ACT_ADDRESS;
    direction_actuator(vehicle);
    fprintf(fp,"\nTestcase 2\n");
    fprintf(fp,"Expected: %d | Result: %d\n", CTRL_ADDRESS, vehicle->Comm_bus_address);
    fprintf(fp,"Expected: %f | Result: %f\n", 12.0, vehicle->direction_actuator_pos);
    fprintf(fp,"Expected: %f | Result: %f\n", 1.0, vehicle->Comm_bus_message);

	printf("Press any key to finish\n");
	getchar();
    fclose(fp);
}