#include "header.h"
#include <string.h>

void driver_attitude(double time_sampling, FILE *trjc, struct VEHICLE_STATUS *vehicle_status);

int main(){
    // Define Variables
	VEHICLE_STATUS *vehicle;
    vehicle = (struct VEHICLE_STATUS*) malloc(sizeof(struct VEHICLE_STATUS));
    double time_sampling = 0.01;

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
    char* file_traj = "../../data/Trajectory.csv"; 
    trjc = fopen(file_traj,"r");
    if (trjc == NULL){
        printf("Could not open file %s",file_traj);
        return 1;
    }

    char line[500];
    fgets(line,500,trjc); //Remove header from dataset
    
    // take 1000 iterations after the beginning
    for (int i=0; i<=1000;i++){
        fgets(line,500,trjc);
    } 

    /* Testcase 1 - The aim is moving forwards, the vehicle is stopped far behind it.
    Expected results: gas pedal increase, no move in steering wheel, brake pedal = 0.
    */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,trjc,vehicle);
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.0;
    vehicle->vehicle_speed = 0.0;
    vehicle->gas_pedal_pos = 0.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,trjc,vehicle);
    fprintf(fp,"\nTestcase 1\n");
    fprintf(fp,"Expected: x > 0.0 | Result: %f\n", vehicle->gas_pedal_pos);
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->brake_pedal_pos); 
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->steering_wheel_pos); 

    /* Testcase 2 - The aim is moving forwards, the vehicle is moving in the same direction far behind it.
    Expected results: gas pedal irrelevant, no move in steering wheel, brake pedal = irrelevant.
    */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,trjc,vehicle);
    vehicle->vehicle_position_X = 1.0;
    vehicle->vehicle_position_Y = 20.0;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 0.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,trjc,vehicle);
    fprintf(fp,"\nTestcase 2\n");
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->gas_pedal_pos);
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->brake_pedal_pos); 
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->steering_wheel_pos); 

    /* Testcase 3 - The aim is moving forwards, the vehicle is moving in down direction far behind it.
    Expected results: gas pedal irrelevant, steering wheel increase, brake pedal = irrelevant.
    */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,trjc,vehicle);
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 19.9;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 0.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,trjc,vehicle);
    fprintf(fp,"\nTestcase 3\n");
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->gas_pedal_pos);
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->brake_pedal_pos); 
    fprintf(fp,"Expected: x > 0.0 | Result: %f\n", vehicle->steering_wheel_pos); 

    /* Testcase 4 - The aim is moving forwards, the vehicle is moving in up direction far behind it.
    Expected results: gas pedal irrelevant, steering wheel decrease, brake pedal = irrelevant.
    */
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,trjc,vehicle);
    vehicle->vehicle_position_X = 0.0;
    vehicle->vehicle_position_Y = 20.1;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 0.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,trjc,vehicle);
    fprintf(fp,"\nTestcase 4\n");
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->gas_pedal_pos);
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->brake_pedal_pos); 
    fprintf(fp,"Expected: x < 0.0 | Result: %f\n", vehicle->steering_wheel_pos); 

    /* Testcase 5 - The aim is moving forwards, the vehicle is moving in same direction close behind to it, but a little down.
    Speed higher than expected.
    Expected results: gas pedal decrease or 0, steering wheel increase, brake pedal = irrelevant.
    */
    vehicle->vehicle_position_X = 95.0;
    vehicle->vehicle_position_Y = 19.0;
    driver_attitude(time_sampling,trjc,vehicle);
    vehicle->vehicle_position_X = 95.1;
    vehicle->vehicle_position_Y = 19.0;
    vehicle->vehicle_speed = 11.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,trjc,vehicle);
    fprintf(fp,"\nTestcase 5\n");
    fprintf(fp,"Expected: < %f | Result: %f\n", 10.0, vehicle->gas_pedal_pos);
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->brake_pedal_pos); 
    fprintf(fp,"Expected: x > 0.0 | Result: %f\n", vehicle->steering_wheel_pos); 

    /* Testcase 6 - The aim is moving forwards, the vehicle is moving in same direction close behind to it, but a little up.
    Speed way higher than expected.
    Expected results: gas pedal 0, steering wheel decrease, brake pedal = increase.
    */
    vehicle->vehicle_position_X = 95.0;
    vehicle->vehicle_position_Y = 21.0;
    driver_attitude(time_sampling,trjc,vehicle);
    vehicle->vehicle_position_X = 95.1;
    vehicle->vehicle_position_Y = 21.0;
    vehicle->vehicle_speed = 13.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,trjc,vehicle);
    fprintf(fp,"\nTestcase 6\n");
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->gas_pedal_pos);
    fprintf(fp,"Expected: > %f | Result: %f\n", 0.0, vehicle->brake_pedal_pos); 
    fprintf(fp,"Expected: x < 0.0 | Result: %f\n", vehicle->steering_wheel_pos);

    /* Testcase 7 - The aim is moving forwards, the vehicle is moving in same direction close ahead to it, but a little up.
    Expected results: gas pedal 0, steering wheel decrease, brake pedal = increase.
    */
    vehicle->vehicle_position_X = 105.0;
    vehicle->vehicle_position_Y = 21.0;
    driver_attitude(time_sampling,trjc,vehicle);
    vehicle->vehicle_position_X = 105.1;
    vehicle->vehicle_position_Y = 21.0;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,trjc,vehicle);
    fprintf(fp,"\nTestcase 7\n");
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->gas_pedal_pos);
    fprintf(fp,"Expected: > %f | Result: %f\n", 0.0, vehicle->brake_pedal_pos); 
    fprintf(fp,"Expected: < %f | Result: %f\n", 0.0, vehicle->steering_wheel_pos);

    /* Testcase 8 - The aim is moving forwards, the vehicle is moving in same direction far ahead to it, but a little up.
    Expected results: gas pedal irrelevant, steering wheel decrease, brake pedal = irrevelant.
    */
    vehicle->vehicle_position_X = 150.0;
    vehicle->vehicle_position_Y = 21.0;
    driver_attitude(time_sampling,trjc,vehicle);
    vehicle->vehicle_position_X = 150.1;
    vehicle->vehicle_position_Y = 21.0;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,trjc,vehicle);
    fprintf(fp,"\nTestcase 8\n");
    fprintf(fp,"Expected: %f | Result: %f\n", 10.0, vehicle->gas_pedal_pos);
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->brake_pedal_pos); 
    fprintf(fp,"Expected: < %f | Result: %f\n", 0.0, vehicle->steering_wheel_pos);
    
    /* Testcase 9 - The aim is moving forwards, the vehicle is moving in opposite direction close behind it.
    Expected results: gas pedal 0, steering wheel = 0, brake pedal irrelevant.
    */
    vehicle->vehicle_position_X = 105.1;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,trjc,vehicle);
    vehicle->vehicle_position_X = 105.0;
    vehicle->vehicle_position_Y = 20.0;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,trjc,vehicle);
    fprintf(fp,"\nTestcase 9\n");
    fprintf(fp,"Expected: %f | Result: %f\n", 10.0, vehicle->gas_pedal_pos);
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->brake_pedal_pos); 
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->steering_wheel_pos);

    /* Testcase 10 - The aim is moving forwards, the vehicle is moving in opposite direction close ahead to it.
    Expected results: gas pedal 0, steering wheel decrease, brake pedal irrelevant.
    */
    vehicle->vehicle_position_X = 100.1;
    vehicle->vehicle_position_Y = 20.0;
    driver_attitude(time_sampling,trjc,vehicle);
    vehicle->vehicle_position_X = 100.0;
    vehicle->vehicle_position_Y = 20.0;
    vehicle->vehicle_speed = 10.0;
    vehicle->gas_pedal_pos = 10.0;
    vehicle->brake_pedal_pos = 0.0;
    vehicle->steering_wheel_pos = 0.0;
    driver_attitude(time_sampling,trjc,vehicle);
    fprintf(fp,"\nTestcase 10\n");
    fprintf(fp,"Expected: %f | Result: %f\n", 10.0, vehicle->gas_pedal_pos);
    fprintf(fp,"Expected: %f | Result: %f\n", 0.0, vehicle->brake_pedal_pos); 
    fprintf(fp,"Expected: < %f | Result: %f\n", 0.0, vehicle->steering_wheel_pos);
    /*
    do{
        driver_attitude(time_sampling,trjc,vehicle);
        printf("%f - ", vehicle->steering_wheel_pos);
        printf("%f - ", vehicle->brake_pedal_pos);
        printf("%f\n", vehicle->gas_pedal_pos);
	}while(!feof(trjc));
    */
    printf("Press any key to finish\n");
	getchar();
    fclose(fp);
    fclose(trjc);
}