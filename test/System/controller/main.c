#include "header.h"
#include <string.h>

void controller(struct VEHICLE_STATUS *vehicle_status);

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
    vehicle->vehicle_speed = 5.0;
    vehicle->gas_pedal_pos = 6;
    vehicle->brake_pedal_pos = 7;
    vehicle->steering_wheel_pos = 8;
    vehicle->direction_actuator_pos = 9;
    vehicle->fuel_actuator_pos = 10;
    vehicle->brake_actuator_pos = 11;
    int testcase = 0;
    float expect = 0.0;

    for (int i = 0; i<=50;i++){
        //printf("%d\n", testcase);
	    controller(vehicle);
        fprintf(fp,"Expected: %d | Result: %d\n", testcase, vehicle->Comm_bus_address);
        fprintf(fp,"Expected: %f | Result: %f\n", expect, vehicle->Comm_bus_message);
    }
    
	printf("End of test\n");
    fclose(fp);
}