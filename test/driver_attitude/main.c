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
    char* file_traj = "Trajectory.csv"; 
    trjc = fopen(file_traj,"r");
    if (trjc == NULL){
        printf("Could not open file %s",file_traj);
        return 1;
    }

    char line[1000];
    fgets(line,1000,trjc);
    driver_attitude(time_sampling,trjc,vehicle);
    
    do{
        driver_attitude(time_sampling,trjc,vehicle);
        printf("%f - ", vehicle->steering_wheel_pos);
        printf("%f - ", vehicle->brake_pedal_pos);
        printf("%f\n", vehicle->gas_pedal_pos);
	}while(!feof(trjc));

    printf("Press any key to finish\n");
	getchar();
    fclose(fp);
    fclose(trjc);
}