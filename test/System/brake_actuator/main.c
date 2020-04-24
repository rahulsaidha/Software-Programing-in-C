/*

*/
#include "header.h"
#include <string.h>
#include <stdio.h>

void brake_actuator(struct VEHICLE_STATUS *vehicle_status);

void print_results(FILE* fp,    int testcase, 
                                char comparison_1,                                
                                double expected_1,                                
                                double result_1,
                                char comparison_2,
                                double expected_2,
                                double result_2,
                                char comparison_3,
                                double expected_3,
                                double result_3){
    printf("\nTestcase %d\n", testcase);
    printf("Expected: %c %f | Result: %f\n",comparison_1, expected_1, result_1);
    printf("Expected: %c %f | Result: %f\n",comparison_2, expected_2, result_2); 
    printf("Expected: %c %f | Result: %f\n",comparison_3, expected_3, result_3);
    fprintf(fp,"\nTestcase %d\n", testcase);
    fprintf(fp,"Expected: %c %f | Result: %f\n", comparison_1, expected_1, result_1);
    fprintf(fp,"Expected: %c %f | Result: %f\n", comparison_2, expected_2, result_2); 
    fprintf(fp,"Expected: %c %f | Result: %f\n", comparison_3, expected_3, result_3); 
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
    vehicle->vehicle_wheel_angle = 1.0;
    vehicle->vehicle_wheel_rotation = 2.0;
    vehicle->vehicle_position_X = 3.0;
    vehicle->vehicle_position_Y = 4.0;
    vehicle->vehicle_speed = 5.0;
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
    brake_actuator(vehicle);
    print_results(fp, 0,'=',GAS_PEDAL_SSR_ADDRESS,vehicle->Comm_bus_address,
                        '=',message,vehicle->Comm_bus_message,
                        '=',0.0,0.0);

    //Testcase 1: requesting to device and receiving confirmation
    vehicle->Comm_bus_message = 11.0;
    vehicle->Comm_bus_address = BRAKE_ACT_ADDRESS;
    brake_actuator(vehicle);
    print_results(fp, 1,'=',CTRL_ADDRESS,vehicle->Comm_bus_address,
                        '=',11.0,vehicle->brake_actuator_pos,
                        '=',1.0,vehicle->Comm_bus_message);

    //Testcase 2: requesting again with another value
    vehicle->Comm_bus_message = 12.0;
    vehicle->Comm_bus_address = BRAKE_ACT_ADDRESS;
    brake_actuator(vehicle);    
    print_results(fp, 2,'=',CTRL_ADDRESS,vehicle->Comm_bus_address,
                        '=',12.0,vehicle->brake_actuator_pos,
                        '=',1.0,vehicle->Comm_bus_message);

	printf("End of test\n");
    fclose(fp);
}