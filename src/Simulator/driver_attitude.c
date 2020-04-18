/**!
This function simulates the behaviour of a driver driving the vehicle.
It acts on the steering wheel, gas pedal and brake pedal in trying to follow the
position (called aim) given by the trajectory file.
The aim is the moving position X and Y stored in the file. The function pass 
commands to the vehicle that is mimics the behaviour of a driver.
It does not return any value, but modify the values in the vehicle_status.
driver_attitude
@param[in] The time sampling of the input file *trjc
@param[in] Trajectory of the vehicle in .csv file
@param[out] vehicle_status structure containing the vehicle parameters
*/

#include "header.h"
#include <string.h>

#define SPEED_TOLERANCE 1.15 /* Threshold for brake */
#define SPEED_REACT_A 0.1 /* How agressive it accelerates */
#define SPEED_REACT_B 0.7 /* How agressive it brakes */
#define ATT_REACT 0.5 /* How fast steering wheel moves */

void driver_attitude(double time_sampling, 
                    FILE *trjc, 
                    struct VEHICLE_STATUS *vehicle_status){

	/* Taking one row of data from file */
	char line[500];
    fgets(line,500,trjc);
    /* Parsing .csv file */
    char *value;
    char *eptr;
    value = strtok(line, ",");
    double time = strtod(value, &eptr);
    value = strtok(NULL, ",");
    double X = strtod(value, &eptr);
    value = strtok(NULL, ",");
    double Y = strtod(value, &eptr);
    value = strtok(NULL, ",");
    double Speed = strtod(value, &eptr);

    /* Computing the differences in trajectories */
    static double last_real_X = 0;
    static double last_real_Y = 0;
    static double last_desired_X = 0;
    static double last_desired_Y = 0;
    double head; /* Actual vehicle orientation */
    double head_desired; /* Orientation from trajectory */
    double head_aim; /* Orientation to the goal */
    double error_X; /* Error in position */
    double error_Y; /* Error in position */
    double error_head; /* Error in orientation */
    double error_aim; /* Difference between orientation and aim */
    double distance; /* How far position is from the goal */
    error_X = X - vehicle_status->vehicle_position_X;
    error_Y = Y - vehicle_status->vehicle_position_Y;
    distance = sqrt((error_X*error_X) + (error_Y*error_Y)); /* L2 norm of error vector */
    head = atan2(vehicle_status->vehicle_position_Y - last_real_Y, vehicle_status->vehicle_position_X - last_real_X);
	head_desired = atan2(Y - last_desired_Y,X - last_desired_X);
	head_aim = atan2(error_Y,error_X);
    /* Computing the angle differences for each quadrant */   
    if (abs(head-head_desired)>PI){
        if(head>=0){
            error_head = (-head +head_desired + 2*PI);
        }
        else{
            error_head = (-head +head_desired - 2*PI);
        }
    }
    else{
        error_head = (-head +head_desired);
    }
    if (abs(head-head_aim)>PI){
        if(head>=0){
            error_aim = (-head +head_aim + 2*PI);
        }
        else{
            error_aim = (-head +head_aim - 2*PI);
        }
    }
    else{
        error_aim = (-head +head_aim);
    }

    /* Passing information to the next iteration */
    last_real_X = vehicle_status->vehicle_position_X;
    last_real_Y = vehicle_status->vehicle_position_Y;
    last_desired_X = X;
    last_desired_Y = Y;

    /* Commands to control the vehicle */
    /* Speed Control */
    double error_speed = Speed - vehicle_status->vehicle_speed;
    double accel = vehicle_status->gas_pedal_pos;
    double brake = vehicle_status->brake_pedal_pos;
    /* Brake if vehicle is ahead of the aim */
    if((abs(error_head) < 0.17) && (abs(error_aim) > 0.30) && (distance < 10.0)){
    	 accel = 0;
    	 brake = brake + SPEED_REACT_B*1*time_sampling;
    }
  	/* Brake if too much speed; else keep controlling acceleration */
    else if (vehicle_status->vehicle_speed > Speed*SPEED_TOLERANCE){
    	 accel = 0;
    	 brake = brake - SPEED_REACT_B*error_speed*time_sampling;
    }
    else{
    	 accel = accel + SPEED_REACT_A*error_speed*time_sampling;
    	 brake = 0;
    }
    /* Limits the action of the pedals */
    if (brake>100){
    	brake = 100;
    }
    if (brake<0){
    	brake = 0;
    }
    if (accel>100){
    	accel = 100;
    }
    if (accel<0){
    	accel = 0;
    }
    /* Pass information to the vehicle */
    vehicle_status->brake_pedal_pos = brake;
    vehicle_status->gas_pedal_pos = accel;
    /* Orientation */
    printf("%f\n", error_aim);
    double steering = vehicle_status->steering_wheel_pos;
    steering = steering + ATT_REACT*error_aim*time_sampling;
	/* limits the action of the steering wheel*/
	if (steering>100){
		steering = 100;
	} 
	if (steering<-100){
		steering = -100;
	}
    /* Pass information to the vehicle */
	vehicle_status->steering_wheel_pos = steering;
}