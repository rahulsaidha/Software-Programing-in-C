#include "header.h"
#include "main.h"
#include <string.h>

/*
void simulator(struct VEHICLE_STATUS *vehicle_status) {
    static double total_time = 0;
    double *time_sampling;
    *time_sampling = differential_time();
    total_time = total_time + time_sampling;
    vehicle_angle(vehicle_status, time_sampling);
    motor_rotation(vehicle_status, time_sampling);
    vehicle_velocity(vehicle_status, time_sampling);
    position_integration(vehicle_status, time_sampling);
    driver_attitude(vehicle_status);
    // environment_status(vehicle_status); release 3
    information_display(vehicle_status);
}
*/
void system(struct VEHICLE_STATUS *vehicle_status) {
    controller(vehicle_status);
    gas_pedal_sensor(vehicle_status);
    brake_pedal_sensor(vehicle_status);
    steering_wheel_sensor(vehicle_status);
    wheel_sensor(vehicle_status);
    direction_actuator(vehicle_status);
    fuel_actuator(vehicle_status);
    brake_actuator(vehicle_status);
    //range_sensor(vehicle_status); release 3
    //vision_sensor(vehicle_status); release 3
}
    
int main(void)
{
    VEHICLE_STATUS *vehicle;
    vehicle = (struct VEHICLE_STATUS*) malloc(sizeof(struct VEHICLE_STATUS));
   
    // Open Trajectory
    FILE *trjc;
    char* file_traj = "../../data/Trajectory.csv"; 
    trjc = fopen(file_traj,"r");
    if (trjc == NULL){
        printf("Could not open file %s",file_traj);
        return 1;
    }

    // Open Log file
    FILE *fp;
    char str[100];
    char* filename = "log.txt";
    fp = fopen(filename, "w");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    vehicle->vehicle_wheel_angle = 1.0;
    vehicle->vehicle_wheel_rotation = 2.0;
    vehicle->vehicle_position_X = 3.0;
    vehicle->vehicle_position_Y = 4.0;
    vehicle->motor_rotation = 5.0;

    vehicle->gas_pedal_pos = 6.0;
    vehicle->brake_pedal_pos = 7.0;
    vehicle->steering_wheel_pos = 8.0;

    vehicle->direction_actuator_pos = 9.0;
    vehicle->fuel_actuator_pos = 10.0;
    vehicle->brake_actuator_pos = 11.0;

    int testcase = 0;
    double expect = 0.0;

    char line[50];
    fgets(line,50,trjc); // Remove header from csv
    
    do{
        //simulator(vehicle_status);
        fgets(line,50,trjc);
        system(vehicle);
    }while(!feof(trjc));
    
    printf("Gas sensor: %f\n", vehicle->gas_pedal_pos);
    printf("Fuel Act: %f\n", vehicle->fuel_actuator_pos);
    printf("Brake sensor: %f\n", vehicle->brake_pedal_pos);
    printf("Brake Act: %f\n", vehicle->brake_actuator_pos);
    printf("Steering wheel sensor: %f\n", vehicle->steering_wheel_pos);
    printf("Steering wheel Act: %f\n", vehicle->direction_actuator_pos);
    
    printf("Press any key to finish\n");
    getchar();
    fclose(fp);
    fclose(trjc);
}