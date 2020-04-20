#include "header.h"
#include "main.h"
#include <string.h>
#include <time.h>

void print_results(FILE* fp,    int testcase, 
                                char comparison_1,                                
                                double expected_1,                                
                                double result_1,
                                char comparison_2,
                                double expected_2,
                                double result_2){
    printf("\nTestcase %d\n", testcase);
    printf("Expected: %c %f | Result: %f\n",comparison_1, expected_1, result_1);
    //printf("Expected: %c %f | Result: %f\n",comparison_2, expected_2, result_2); 
    fprintf(fp,"\nTestcase %d\n");
    fprintf(fp,"Expected: %c %f | Result: %f\n", 0.0, result_1);
    //fprintf(fp,"Expected: %c %f | Result: %f\n", 0.0, result_2); 
}

int main(void)
{
    VEHICLE_STATUS *vehicle;
    vehicle = (struct VEHICLE_STATUS*) malloc(sizeof(struct VEHICLE_STATUS));

    // Open Log file
    FILE *fp;
    char str[100];
    char* filename = "log.txt";
    fp = fopen(filename, "w");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 0.0;
    vehicle->motor_rotation = 0.0;

    vehicle->gas_pedal_pos = 0.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;

    vehicle->direction_actuator_pos = 0.0;
    vehicle->fuel_actuator_pos = 0.0;
    vehicle->brake_actuator_pos = 0.0;

    int testcase = 0;
    double expect = 0.0;

    /* Testcase 1 - No movement when no power; */
    vehicle->fuel_actuator_pos = 0.0;
    vehicle->brake_actuator_pos = 0.0;
    vehicle->vehicle_speed = 0.0;
    vehicle_velocity(0.01, vehicle);
    print_results(fp,1,'=',0.0,vehicle->vehicle_speed,'=',0.0,0.0);

    /* Testcase 2 - Power on;
    Expected results: speed increase */
    vehicle->fuel_actuator_pos = 30.0;
    vehicle->brake_actuator_pos = 0.0;
    vehicle->vehicle_speed = 0.0;
    vehicle_velocity(0.01, vehicle);
    print_results(fp,2,'>',0.0,vehicle->vehicle_speed,'=',0.0,0.0);

    /* Testcase 3 - Power off when speed != 0;
    Expected results: speed decrease */
    vehicle->fuel_actuator_pos = 0.0;
    vehicle->brake_actuator_pos = 0.0;
    vehicle->vehicle_speed = 30.0;
    vehicle_velocity(0.01, vehicle);
    print_results(fp,3,'<',30.0,vehicle->vehicle_speed,'=',0.0,0.0);

    /* Testcase 4 - Brake when speed != 0;
    Expected results: speed decrease */
    vehicle->fuel_actuator_pos = 0.0;
    vehicle->brake_actuator_pos = 100.0;
    vehicle->vehicle_speed = 30.0;
    vehicle_velocity(0.01, vehicle);
    print_results(fp,4,'<',30.0,vehicle->vehicle_speed,'=',0.0,0.0);

    /* Testcase 5 - Brake when speed = 0;
    Expected results: speed 0; no backward moviment */
    vehicle->fuel_actuator_pos = 0.0;
    vehicle->brake_actuator_pos = 100.0;
    vehicle->vehicle_speed = 0.0;
    vehicle_velocity(0.01, vehicle);
    print_results(fp,5,'=',0.0,vehicle->vehicle_speed,'=',0.0,0.0);

    /* Testcase 6 - Maximum Speed;
    Expected results: speed at least 30m/s */
    vehicle->fuel_actuator_pos = 100.0;
    vehicle->brake_actuator_pos = 0.0;
    vehicle->vehicle_speed = 0.0;
    for (int i=0; i<=10000; i++){
        vehicle_velocity(0.01, vehicle);
    }
    print_results(fp,6,'>',30.0,vehicle->vehicle_speed,'=',0.0,0.0);

    /* Extra test for adjusting parameters */
    vehicle->fuel_actuator_pos = 0.0;    
    vehicle->brake_actuator_pos = 100.0;
    vehicle->vehicle_speed = 30.0;
    for (int i=0; i<=100; i++){
        vehicle_velocity(0.01, vehicle);
    }
    print_results(fp,10,'>',0.0,vehicle->vehicle_speed,'=',0.0,0.0);

    printf("Press any key to finish\n");
    getchar();
    fclose(fp);
}