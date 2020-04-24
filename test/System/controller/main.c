#include "header.h"
#include "main.h"
#include <string.h>
#include <stdio.h>

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


    /* Testcase 1 - signals from sensors are been followed to actuators */
    for (int i = 0; i<=500;i++){
	    controller(vehicle);
    	gas_pedal_sensor(vehicle);
    	brake_pedal_sensor(vehicle);
   	 	steering_wheel_sensor(vehicle);
    	wheel_sensor(vehicle);
    	direction_actuator(vehicle);
    	fuel_actuator(vehicle);
    	brake_actuator(vehicle);
    }
    print_results(fp, 1,'=',vehicle->gas_pedal_pos,vehicle->fuel_actuator_pos,
                        '=',vehicle->brake_pedal_pos,vehicle->brake_actuator_pos,
                        '=',vehicle->steering_wheel_pos,vehicle->direction_actuator_pos);
    
	printf("End of test\n");
    fclose(fp);
}