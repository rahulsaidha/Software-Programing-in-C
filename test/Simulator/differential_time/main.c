#include "header.h"
#include "main.h"
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

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
    double time_sampling;
    double time;

    /* Testcase 1 - Return the time in the first call; 
    Expected: zero */      
    time_sampling = differential_time();  
    print_results(fp,1,'=',0.0,time_sampling,'=',0.0,0.0);

    /* Testcase 2 - Return the desired time; 
    Expected: 2 seconds */      
    time_sampling = differential_time();  
    sleep(2);
    time_sampling = differential_time();
    print_results(fp,2,'=',2.0,time_sampling,'=',0.0,0.0);
    
    /* Testcase 3 - Return 0 time; 
    Expected: zero */      
    time_sampling = differential_time();  
    time_sampling = differential_time();
    print_results(fp,3,'=',0.0,time_sampling,'=',0.0,0.0);

    printf("Press any key to finish\n");
    getchar();
    fclose(fp);
}