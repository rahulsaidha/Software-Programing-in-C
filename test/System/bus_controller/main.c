#include "header.h"
#include <stdio.h>

int bus_controller(double steering_wheel_pos, double gas_pedal_pos, double brake_pedal_pos, struct VEHICLE_STATUS *vehicle_status);

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
    fprintf(fp,"\nTestcase %d\n", testcase);
    fprintf(fp,"Expected: %c %f | Result: %f\n", comparison_1, expected_1, result_1);
    fprintf(fp,"Expected: %c %f | Result: %f\n", comparison_2, expected_2, result_2);   
}

int main(){
    // Define Variables
	VEHICLE_STATUS *vehicle;
    vehicle = (struct VEHICLE_STATUS*) malloc(sizeof(struct VEHICLE_STATUS));
	static double vehicle_wheel_rotation = 1.0;
    static double gas_pedal_pos = 2.0;
    static double brake_pedal_pos = 3.0;
    static double steering_wheel_pos = 4.0;
    static double direction_actuator_pos = 5.0;
    static double fuel_actuator_pos = 6.0;
    static double brake_actuator_pos = 7.0;

    // Open file
    FILE *fp;
    char str[100];
    char* filename = "log.txt";
    fp = fopen(filename, "w");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    int testcase = 0;
    float expect = 0.0;

    /*
    Testcase 1 - Several sequential calls with the same input parameters. 
    Expected output: the address returned by the function should be the same in the vehicle_status->bus_address;
    Testcase 2 - Several sequential calls with the same input parameters. 
    Expected output: return a different address in each call, until the sequence finishes, and then repeat the addresses;
    */ 
    for (int i = 0; i<=15;i++){
	   testcase = bus_controller(steering_wheel_pos, gas_pedal_pos, brake_pedal_pos, vehicle);
       print_results(fp,1,'=',testcase, vehicle->Comm_bus_address,'=',0.0,0.0);
    }

    /* Testcase 3 - Several sequential calls with steering_wheel_pos = 100, all others = 1. Expected output:
    vehicle_status.bus_message = 1 for all cases except when address returned equal to direction
    actuator address, in this case, vehicle_status->bus_message = 100;
    */
    vehicle_wheel_rotation = 1.0;
    gas_pedal_pos = 1.0;
    brake_pedal_pos = 1.0;
    steering_wheel_pos = 100.0;
    direction_actuator_pos = 1.0;
    fuel_actuator_pos = 1.0;
    brake_actuator_pos = 1.0;
    for (int i = 0; i<=15;i++){
        testcase = bus_controller(steering_wheel_pos, gas_pedal_pos, brake_pedal_pos, vehicle);
        if(testcase == DIR_ACT_ADDRESS){
            expect = 100.0;
        }
        else{
            expect = 1.0;
        }
        print_results(fp,3,'=',testcase, vehicle->Comm_bus_address,'=',expect,vehicle->Comm_bus_message);
    }
    
    /* Testcase 4 - Several sequential calls with gas_pedal_pos = 100, all others = 1. Expected output:
    vehicle_status.bus_message = 1 for all cases except when address returned equal to fuel
    actuator address, in this case, vehicle_status.bus_message = 100;
    */
    vehicle_wheel_rotation = 1.0;
    gas_pedal_pos = 100.0;
    brake_pedal_pos = 1.0;
    steering_wheel_pos = 1.0;
    direction_actuator_pos = 1.0;
    fuel_actuator_pos = 1.0;
    brake_actuator_pos = 1.0;
    for (int i = 0; i<=15;i++){
        testcase = bus_controller(steering_wheel_pos, gas_pedal_pos, brake_pedal_pos, vehicle);
        if(testcase == FUEL_ACT_ADDRESS){
            expect = 100.0;
        }
        else{
            expect = 1.0;
        }
        print_results(fp,4,'=',testcase, vehicle->Comm_bus_address,'=',expect,vehicle->Comm_bus_message);
    }    

    /* Testcase 5 - Several sequential calls with brake_pedal_pos = 100, all others = 1. Expected output:
    vehicle_status.bus_message = 1 for all cases except when address returned equal to brake
    actuator address, in this case, vehicle_status.bus_message = 100;
    */
    vehicle_wheel_rotation = 1.0;
    gas_pedal_pos = 1.0;
    brake_pedal_pos = 100.0;
    steering_wheel_pos = 1.0;
    direction_actuator_pos = 1.0;
    fuel_actuator_pos = 1.0;
    brake_actuator_pos = 1.0;
    for (int i = 0; i<=15;i++){
        testcase = bus_controller(steering_wheel_pos, gas_pedal_pos, brake_pedal_pos, vehicle);
        if(testcase == BRAKE_ACT_ADDRESS){
            expect = 100.0;
        }
        else{
            expect = 1.0;
        }
        print_results(fp,4,'=',testcase, vehicle->Comm_bus_address,'=',expect,vehicle->Comm_bus_message);
    }

    /* Testcase 6 - Several sequential calls with steering_wheel_pos = 100, gas_pedal_pos = 100, brake_pedal_pos = 100. 
    Expected output: vehicle_status.bus_message = 1 for returned address equal to brake
    sensor or steering sensor or wheel sensor addresses, or vehicle_status.bus_message = 1 for
    returned address equal to brake actuator or fuel actuator or direction actuator addresses.
    */
    vehicle_wheel_rotation = 1.0;
    gas_pedal_pos = 100.0;
    brake_pedal_pos = 100.0;
    steering_wheel_pos = 100.0;
    direction_actuator_pos = 1.0;
    fuel_actuator_pos = 1.0;
    brake_actuator_pos = 1.0;
    for (int i = 0; i<=15;i++){
        testcase = bus_controller(steering_wheel_pos, gas_pedal_pos, brake_pedal_pos, vehicle);
        if((testcase == DIR_ACT_ADDRESS) || (testcase == FUEL_ACT_ADDRESS) || (testcase == BRAKE_ACT_ADDRESS)){
            expect = 100.0;
        }
        else{
            expect = 1.0;
        }
        print_results(fp,5,'=',testcase, vehicle->Comm_bus_address,'=',expect,vehicle->Comm_bus_message);
    }

	printf("End of test\n");
    fclose(fp);
}