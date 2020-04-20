#include "header.h"
#include "main.h"
#include <string.h>
#include <time.h>

void print_results(FILE* fp, struct VEHICLE_STATUS* vehicle,
                                int testcase, 
                                char comparison_1,                                
                                double expected_1,                                
                                double result_1,
                                char comparison_2,
                                double expected_2,
                                double result_2){
    printf("\nTestcase %d\n", testcase);
    printf("Expected: %c %f | Result: %f\n",comparison_1, expected_1, vehicle->vehicle_wheel_angle);
    printf("Expected: %c %f | Result: %f\n",comparison_2, expected_2, vehicle->vehicle_angle); 
    fprintf(fp,"\nTestcase 1\n");
    fprintf(fp,"Expected: %c %f | Result: %f\n", 0.0, vehicle->vehicle_wheel_angle);
    fprintf(fp,"Expected: %c %f | Result: %f\n", 0.0, vehicle->vehicle_angle); 
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

    /* Testcase 1 - No movement when steering wheel = 0; */
    vehicle->direction_actuator_pos = 0.0;
    vehicle_angle(20, 0.01, vehicle);
    print_results(fp,vehicle,1,'=',0.0,vehicle->vehicle_wheel_angle,'=',0.0,vehicle->vehicle_angle);
    
    /* Testcase 2 - Direction actuator to the left;
    Expected results: angle increase; vehicle wheel angle positive. */
    vehicle->direction_actuator_pos = 10.0;
    vehicle_angle(20, 0.01, vehicle);
    print_results(fp,vehicle,2,'>',0.0,vehicle->vehicle_wheel_angle,'>',0.0,vehicle->vehicle_angle);

    /* Testcase 3 - Direction actuator to the right;
    Expected results: angle decrease; vehicle wheel angle negative. */
    vehicle->vehicle_angle = 0.0;
    vehicle->direction_actuator_pos = -10.0;
    vehicle_angle(20, 0.01, vehicle);
    print_results(fp,vehicle,3,'<',0.0,vehicle->vehicle_wheel_angle,'<',0.0,vehicle->vehicle_angle);

    /* Testcase 4 - Angle limit to positive with more input to positive
    Expected results: angle loop to -PI; vehicle wheel angle positive. */
    vehicle->direction_actuator_pos = 10.0;
    vehicle->vehicle_angle = PI - 0.001;
    vehicle_angle(20, 0.01, vehicle);
    print_results(fp,vehicle,4,'>',0.0,vehicle->vehicle_wheel_angle,'~',-3.1415,vehicle->vehicle_angle);

    /* Testcase 5 - Angle limit to nogative with more input to nogative
    Expected results: angle loop to PI; vehicle wheel angle negative. */
    vehicle->direction_actuator_pos = -10.0;
    vehicle->vehicle_angle = -PI + 0.001;
    vehicle_angle(20, 0.01, vehicle);
    print_results(fp,vehicle,5,'<',0.0,vehicle->vehicle_wheel_angle,'~',3.141,vehicle->vehicle_angle);

    /* Testcase 6 - No movement when velocity = 0 and direction moved to the left; 
    Expected result: no change in vehicle angle; wheels to positive. */
    vehicle->vehicle_angle = 2.0;
    vehicle->direction_actuator_pos = 10.0;
    vehicle_angle(0, 0.01, vehicle);
    print_results(fp,vehicle,6,'>',0.0,vehicle->vehicle_wheel_angle,'=',2.0,vehicle->vehicle_angle);

    printf("Press any key to finish\n");
    getchar();
    fclose(fp);
}