#include "header.h"
#include "main.h"
#include <string.h>
#include <time.h>

//#ifdef _WIN32
//#include <Windows.h>
//#else
//#include <unistd.h>
//#endif

void simulator(FILE *trjc, struct VEHICLE_STATUS *vehicle_status, FILE *fp) {

    static double total_time = 0;
    double time_sampling;
    time_sampling = differential_time();
    total_time += time_sampling;

    vehicle_velocity(time_sampling, vehicle_status);
    vehicle_angle(time_sampling, vehicle_status);
    position_integration(time_sampling, vehicle_status);

    /* Input time sampling = 0.01;
    To match the input sampling time with the current time, the new input should be called only
    once per time sampling = 0.01.
    */
    static int k = 0;
    if (total_time > 0.01*k){
        driver_attitude(0.01, total_time, trjc, vehicle_status);
        if (k%1000 == 0){
            information_display(total_time, vehicle_status, fp); 
        }
        k++;
    }
}
/*
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
*/
int main(void)
{
    VEHICLE_STATUS *vehicle;
    vehicle = (struct VEHICLE_STATUS*) malloc(sizeof(struct VEHICLE_STATUS));
   
    // Open Trajectory
    FILE *trjc;
    char* file_traj = "../../../data/Trajectory.csv"; 
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

    vehicle->vehicle_position_X = 3.0;
    vehicle->vehicle_position_Y = 4.0;

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
        simulator(trjc, vehicle, fp);
    }while(!feof(trjc));
    
    printf("Gas sensor: %f\n", vehicle->gas_pedal_pos);
    printf("Fuel Act: %f\n", vehicle->fuel_actuator_pos);
    printf("Brake sensor: %f\n", vehicle->brake_pedal_pos);
    printf("Brake Act: %f\n", vehicle->brake_actuator_pos);
    printf("Steering wheel sensor: %f\n", vehicle->steering_wheel_pos);
    printf("Steering wheel Act: %f\n", vehicle->direction_actuator_pos);
    
    printf("End of the test\n");
    fclose(fp);
    fclose(trjc);
}