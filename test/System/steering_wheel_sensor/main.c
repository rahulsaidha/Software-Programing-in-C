#include "header.h"
#include <string.h>
#include <stdio.h>

void steering_wheel_sensor(struct VEHICLE_STATUS *vehicle_status);

void print_results(FILE* fp,    int testcase, 
                                char comparison_1,                                
                                double expected_1,                                
                                double result_1,
                                char comparison_2,
                                double expected_2,
                                double result_2){
    printf("\nTestcase %d\n", testcase);
    printf("Expected: %c %f | Result: %f\n",comparison_1, expected_1, result_1);
    printf("Expected: %c %f | Result: %f\n",comparison_2, expected_2, result_2); 
    fprintf(fp,"\nTestcase %d\n", testcase);
    fprintf(fp,"Expected: %c %f | Result: %f\n", comparison_1, expected_1, result_1);
    fprintf(fp,"Expected: %c %f | Result: %f\n", comparison_2, expected_2, result_2);   
}

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
    
    double message;

    //Testcase 0: requesting another device
    message = 0;
    vehicle->Comm_bus_address = GAS_PEDAL_SSR_ADDRESS;
    steering_wheel_sensor(vehicle);
    print_results(fp,0,'=',GAS_PEDAL_SSR_ADDRESS,vehicle->Comm_bus_address,
                       '=',message,vehicle->Comm_bus_message);

    //Testcase 1: requesting and receiving from device
    vehicle->Comm_bus_address = STEERING_SSR_ADDRESS;
    steering_wheel_sensor(vehicle);
    print_results(fp,1,'=',CTRL_ADDRESS,vehicle->Comm_bus_address,
                       '=',vehicle->steering_wheel_pos,vehicle->Comm_bus_message);

    //Testcase 2: requesting again with another value
    vehicle->steering_wheel_pos = 10;
    vehicle->Comm_bus_address = STEERING_SSR_ADDRESS;
    steering_wheel_sensor(vehicle);
    print_results(fp,2,'=',CTRL_ADDRESS,vehicle->Comm_bus_address,
                       '=',vehicle->steering_wheel_pos,vehicle->Comm_bus_message);

	printf("End of test\n");
    fclose(fp);
}