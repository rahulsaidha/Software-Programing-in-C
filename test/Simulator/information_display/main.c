#include "header.h"
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void information_display(double time, struct VEHICLE_STATUS* vehicle);

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
    char* file_traj = "../../../data/Trajectory.csv"; 
    trjc = fopen(file_traj,"r");
    if (trjc == NULL){
        printf("Could not open file %s",file_traj);
        return 1;
    }
    
    char line[50];
    int k = 0;
    do{
        fgets(line, 100,trjc);
        if(k%1000 == 0){
            information_display((double)k, vehicle);    
            sleep(1);        
        }
        k++;
	}while(!feof(trjc));

    printf("Simulation finished\nPress any key to close\n");
	getchar();
    fclose(fp);
    fclose(trjc);
}