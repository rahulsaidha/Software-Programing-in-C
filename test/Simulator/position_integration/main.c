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
    printf("Expected: %c %f | Result: %f\n",comparison_2, expected_2, result_2); 
    fprintf(fp,"\nTestcase - %d\n", testcase);
    fprintf(fp,"Expected: %c %f | Result: %f\n",comparison_1, expected_1, result_1);
    fprintf(fp,"Expected: %c %f | Result: %f\n",comparison_2, expected_2, result_2);
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

    vehicle->gas_pedal_pos = 0.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;

    vehicle->direction_actuator_pos = 0.0;
    vehicle->fuel_actuator_pos = 0.0;
    vehicle->brake_actuator_pos = 0.0;

    int testcase = 0;
    double expect = 0.0;

    /* Testcase 1 - No movement when no speed; */
    vehicle->vehicle_angle = PI;
    vehicle->vehicle_speed = 0;
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 0.0;
    position_integration(0.01, vehicle);
    print_results(fp,1,'=',0.0,vehicle->vehicle_position_X,'=',0.0,vehicle->vehicle_position_Y);

    /* Testcase 2 -  moviment in positive X;
    Expect X increase, Y same */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 0.0;
    vehicle->vehicle_angle = 0;
    vehicle->vehicle_speed = 20;
    position_integration(0.01, vehicle);
    print_results(fp,2,'>',0.0,vehicle->vehicle_position_X,'=',0.0,vehicle->vehicle_position_Y);

    /* Testcase 2 - moviment in negative X, PI;
    Expect X decrease, Y same */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 0.0;
    vehicle->vehicle_angle = PI;
    vehicle->vehicle_speed = 20;
    position_integration(0.01, vehicle);
    print_results(fp,2,'<',0.0,vehicle->vehicle_position_X,'=',0.0,vehicle->vehicle_position_Y);
    
    /* Testcase 3 - moviment in negative X, -PI;
    Expect X decrease, Y same */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 0.0;
    vehicle->vehicle_angle = - PI;
    vehicle->vehicle_speed = 20;
    position_integration(0.01, vehicle);
    print_results(fp,3,'<',0.0,vehicle->vehicle_position_X,'=',0.0,vehicle->vehicle_position_Y);

    /* Testcase 4 - moviment in positive Y, PI/2;
    Expect X same, Y increase */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 0.0;
    vehicle->vehicle_angle = PI/2.0;
    vehicle->vehicle_speed = 20;
    position_integration(0.01, vehicle);
    print_results(fp,4,'=',0.0,vehicle->vehicle_position_X,'>',0.0,vehicle->vehicle_position_Y);

    /* Testcase 5 - moviment in negative X, -PI;
    Expect X decrease, Y same */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 0.0;
    vehicle->vehicle_angle = - PI/2.0;
    vehicle->vehicle_speed = 20;
    position_integration(0.01, vehicle);
    print_results(fp,5,'=',0.0,vehicle->vehicle_position_X,'<',0.0,vehicle->vehicle_position_Y);

    /* Testcase 6 - moviment in positive X, positive Y;
    Expect X decrease, Y same */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 0.0;
    vehicle->vehicle_angle = PI/4.0;
    vehicle->vehicle_speed = 20;
    position_integration(0.01, vehicle);
    print_results(fp,6,'>',0.0,vehicle->vehicle_position_X,'>',0.0,vehicle->vehicle_position_Y);

    /* Testcase 7 - moviment in positive X, negative Y;
    Expect X decrease, Y same */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 0.0;
    vehicle->vehicle_angle = - PI/4.0;
    vehicle->vehicle_speed = 20;
    position_integration(0.01, vehicle);
    print_results(fp,7,'>',0.0,vehicle->vehicle_position_X,'<',0.0,vehicle->vehicle_position_Y);

    /* Testcase 8 - moviment in negative X, positive Y;
    Expect X decrease, Y same */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 0.0;
    vehicle->vehicle_angle = PI*0.75;
    vehicle->vehicle_speed = 20;
    position_integration(0.01, vehicle);
    print_results(fp,8,'<',0.0,vehicle->vehicle_position_X,'>',0.0,vehicle->vehicle_position_Y);

    /* Testcase 9 - moviment in negative X, negative Y;
    Expect X decrease, Y same */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 0.0;
    vehicle->vehicle_angle = - PI*0.75;
    vehicle->vehicle_speed = 20;
    position_integration(0.01, vehicle);
    print_results(fp,9,'<',0.0,vehicle->vehicle_position_X,'<',0.0,vehicle->vehicle_position_Y);

    printf("End of the test\n");
    fclose(fp);
}