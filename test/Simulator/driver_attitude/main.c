#include "header.h"
#include <string.h>
#include <stdio.h>

void driver_attitude(double time_sampling, double total_time, FILE *trjc, struct VEHICLE_STATUS *vehicle_status);

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
    printf("\nTestcase - %d\n", testcase);
    printf("Expected: %c %f | Result: %f\n",comparison_1, expected_1, result_1);
    printf("Expected: %c %f | Result: %f\n",comparison_2, expected_2, result_2);
    printf("Expected: %c %f | Result: %f\n",comparison_3, expected_3, result_3);  
    fprintf(fp,"\nTestcase - %d\n", testcase);
    fprintf(fp,"Expected: %c %f | Result: %f\n",comparison_1, expected_1, result_1);
    fprintf(fp,"Expected: %c %f | Result: %f\n",comparison_2, expected_2, result_2);
    fprintf(fp,"Expected: %c %f | Result: %f\n",comparison_3, expected_3, result_3);  
}

int main(){
    // Define Variables
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

    // Open Trajectory
    FILE *trjc;
    char* file_traj = "../../../data/Trajectory.csv"; 
    trjc = fopen(file_traj,"r");
    if (trjc == NULL){
        printf("Could not open file %s",file_traj);
        return 1;
    }

    char line[500];
    fgets(line,500,trjc); //Remove header from dataset
    
    // take 50 iterations after the beginning 
    double total_time = 0.01*50.0;
    double time_sampling = 0.01;

    /* Testcase 1 - The aim is moving forwards, the vehicle is stopped far behind it.
    Expected results: gas pedal increase, no move in steering wheel, brake pedal = 0.
    */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.0;
    vehicle->vehicle_speed = 0.0;
    vehicle->gas_pedal_pos = 0.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    print_results(fp, 1, '>',0.0,vehicle->gas_pedal_pos,'=',0.0,vehicle->brake_pedal_pos,'=',0.0,vehicle->steering_wheel_pos);

    /* Testcase 2 - The aim is moving forwards, the vehicle is moving in the same direction far behind it.
    Expected results: gas pedal increase, no move in steering wheel, brake pedal = irrelevant.
    */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    vehicle->vehicle_position_X = 1.0;
    vehicle->vehicle_position_Y = 20.0;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 0.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);    
    total_time += time_sampling;
    print_results(fp, 2,'>',0.0,vehicle->gas_pedal_pos,'=',0.0,vehicle->brake_pedal_pos,'=',0.0,vehicle->steering_wheel_pos);

    /* Testcase 3 - The aim is moving forwards, the vehicle is moving in down direction far behind it.
    Expected results: gas pedal irrelevant, steering wheel increase, brake pedal = irrelevant.
    */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 19.9;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 0.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    print_results(fp, 3,'=',0.0,vehicle->gas_pedal_pos,'=',0.0,vehicle->brake_pedal_pos,'>',0.0,vehicle->steering_wheel_pos);

    /* Testcase 4 - The aim is moving forwards, the vehicle is moving in up direction far behind it.
    Expected results: gas pedal increase, steering wheel decrease, brake pedal = 0.
    */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.1;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 0.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    print_results(fp, 4,'>',0.0,vehicle->gas_pedal_pos,'=',0.0,vehicle->brake_pedal_pos,'<',0.0,vehicle->steering_wheel_pos);

    /* Testcase 5 - The aim is moving forwards, the vehicle is moving in same direction close behind to it, but a little down.
    Speed higher than expected.
    Expected results: gas pedal decrease or 0, steering wheel increase, brake pedal = irrelevant.
    */
    vehicle->vehicle_position_X = 95.0;
    vehicle->vehicle_position_Y = 19.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    vehicle->vehicle_position_X = 95.1;
    vehicle->vehicle_position_Y = 19.0;
    vehicle->vehicle_speed = 11.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    print_results(fp, 5,'<',10.0,vehicle->gas_pedal_pos,'=',0.0,vehicle->brake_pedal_pos,'>',0.0,vehicle->steering_wheel_pos);

    /* Testcase 6 - The aim is moving forwards, the vehicle is moving in same direction close behind to it, but a little up.
    Speed way higher than expected.
    Expected results: gas pedal < 10, steering wheel decrease, brake pedal = 0.
    */
    vehicle->vehicle_position_X = 95.0;
    vehicle->vehicle_position_Y = 21.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    vehicle->vehicle_position_X = 95.1;
    vehicle->vehicle_position_Y = 21.0;
    vehicle->vehicle_speed = 13.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    print_results(fp, 6,'<',10.0,vehicle->gas_pedal_pos,'>',0.0,vehicle->brake_pedal_pos,'<',0.0,vehicle->steering_wheel_pos);

    /* Testcase 7 - The aim is moving forwards, the vehicle is moving in same direction close ahead to it, but a little up.
    Expected results: gas pedal 0, steering wheel decrease, brake pedal = increase.
    */
    vehicle->vehicle_position_X = 105.0;
    vehicle->vehicle_position_Y = 21.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    vehicle->vehicle_position_X = 105.1;
    vehicle->vehicle_position_Y = 21.0;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    print_results(fp, 7,'=',0.0,vehicle->gas_pedal_pos,'>',0.0,vehicle->brake_pedal_pos,'<',0.0,vehicle->steering_wheel_pos);

    /* Testcase 8 - The aim is moving forwards, the vehicle is moving in same direction far ahead to it, but a little up.
    Expected results: gas pedal irrelevant, steering wheel decrease, brake pedal = irrevelant.
    */
    vehicle->vehicle_position_X = 150.0;
    vehicle->vehicle_position_Y = 21.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    vehicle->vehicle_position_X = 150.1;
    vehicle->vehicle_position_Y = 21.0;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    print_results(fp, 8,'=',10.0,vehicle->gas_pedal_pos,'=',0.0,vehicle->brake_pedal_pos,'<',0.0,vehicle->steering_wheel_pos);
    
    /* Testcase 9 - The aim is moving forwards, the vehicle is moving in opposite direction close behind it.
    Expected results: gas pedal 0, steering wheel = 0, brake pedal irrelevant.
    */
    vehicle->vehicle_position_X = 105.1;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    vehicle->vehicle_position_X = 105.0;
    vehicle->vehicle_position_Y = 20.0;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    print_results(fp, 9,'<',10.0,vehicle->gas_pedal_pos,'=',0.0,vehicle->brake_pedal_pos,'=',0.0,vehicle->steering_wheel_pos);

    /* Testcase 10 - The aim is moving forwards, the vehicle is moving in opposite direction close ahead to it.
    Expected results: gas pedal ~ 10, steering wheel decrease, brake pedal irrelevant.
    */
    vehicle->vehicle_position_X = 95.1;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    vehicle->vehicle_position_X = 95.0;
    vehicle->vehicle_position_Y = 20.0;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,total_time,trjc,vehicle);
    total_time += time_sampling;
    print_results(fp, 10,'~',10.0,vehicle->gas_pedal_pos,'=',0.0,vehicle->brake_pedal_pos,'<',0.0,vehicle->steering_wheel_pos);

    printf("End of the test\n");
    fclose(fp);
    fclose(trjc);
}