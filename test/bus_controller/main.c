#include "header.h"

int bus_controller(double steering_wheel_pos, double gas_pedal_pos, double brake_pedal_pos, struct VEHICLE_STATUS *vehicle_status);

int main(){
    // Define Variables
	VEHICLE_STATUS *vehicle;
    vehicle = (struct VEHICLE_STATUS*) malloc(sizeof(struct VEHICLE_STATUS));
	static double vehicle_wheel_rotation = 0;
    static double gas_pedal_pos = 0;
    static double brake_pedal_pos = 0;
    static double steering_wheel_pos = 0;
    static double direction_actuator_pos = 0;
    static double fuel_actuator_pos = 0;
    static double brake_actuator_pos = 0;

    // Open file
    FILE *fp;
    char str[100];
    char* filename = "log.txt";
    fp = fopen(filename, "w");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    // Run testcase
    int testcase = 0;
    for (int i = 0; i<=20;i++){
	   testcase = bus_controller(steering_wheel_pos, gas_pedal_pos, brake_pedal_pos, vehicle);
	   //printf("%d\n", testcase);
       fprintf(fp,"%d\n",testcase);
    }
	printf("Press any key to finish\n");
	getchar();
    fclose(fp);
}