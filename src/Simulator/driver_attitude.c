/**
* This function simulates the behaviour of a driver driving the vehicle.
* It acts on the steering wheel, gas pedal and brake pedal in trying to follow 
* the position (called aim) given by the trajectory file.
* The aim is the moving position X and Y stored in the file. The function pass 
* commands to the vehicle that is mimics the behaviour of a driver.
*/

#include "header.h"
#include <string.h>

#define SPEED_TOLERANCE 1.15 // Threshold for brake

#define DISTANCE_FACTOR 0.03 // distance_factor sensitivity
#define SPEED_FACTOR 0.1 // Speed_factor sensitivity
#define SPEED_REACT_A_P 0.1 // How agressive it accelerates proportional
#define SPEED_REACT_A_D 0.1 // How agressive it accelerates derivative
#define SPEED_REACT_B 0.7 // How agressive it brakes
#define ATT_REACT 0.5 // How fast steering whell moves

void driver_attitude(double time_sampling, 
                    double total_time,
                    FILE *trjc, 
                    FILE *dr,
                    struct VEHICLE_STATUS *vehicle_status){

    double time;
    double X;
    double Y;
    double Speed;

    while(total_time>time && (!feof(trjc))){
    	// Parsing .csv file 
    	char line[100];
    	char *value;
    	char *eptr;
        fgets(line,100,trjc);
        if(feof(trjc)){
            break;
        }
        value = strtok(line, ",");
        time = strtod(value, &eptr);
        value = strtok(NULL, ",");
        X = strtod(value, &eptr);
        value = strtok(NULL, ",");
        Y = strtod(value, &eptr);
        value = strtok(NULL, ",");
        Speed = strtod(value, &eptr);
    }
    // Computing the differences in trajectories
    static double last_real_X = 0;
    static double last_real_Y = 0;
    static double last_desired_X = 0;
    static double last_desired_Y = 0;
    double head; // Actual vehicle orientation
    double head_desired; // Orientation from trajectory
    double head_aim; // Orientation to the goal
    double error_X; // Error in position
    double error_Y; // Error in position
    double error_head; // Error in orientation
    double error_aim; // Difference between orientation and aim
    double distance; //How far position is from the goal
    double steering = vehicle_status->steering_wheel_pos;
    error_X = X - vehicle_status->vehicle_position_X;
    error_Y = Y - vehicle_status->vehicle_position_Y;
    distance = sqrt((error_X*error_X) + (error_Y*error_Y)); //L2 norm of error vector
    head = vehicle_status->vehicle_angle;
	head_desired = atan2(Y - last_desired_Y,X - last_desired_X);
	head_aim = atan2(error_Y,error_X);
    // Computing the differences for each quadrant     
    if ((head-head_desired)>PI){
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
    if ((head-head_aim)>PI){
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

    // Passing information to the next iteration 
    last_real_X = vehicle_status->vehicle_position_X;
    last_real_Y = vehicle_status->vehicle_position_Y;
    last_desired_X = X;
    last_desired_Y = Y;

    /* Commands to control the vehicle */
    //Speed
    double error_speed = Speed - vehicle_status->vehicle_speed;
    double accel = vehicle_status->gas_pedal_pos;
    double brake = vehicle_status->brake_pedal_pos;
    double distance_factor; // Reduce speed when close to goal
    distance_factor = -(exp(-SPEED_FACTOR*distance)) + 1; 
    //Brake if vehicle is ahead of the aim
    if((abs(error_head) < 0.17) && (abs(error_aim) > 0.30) && (distance < 10.0)){
    	 accel = 0;
    	 brake = brake + SPEED_REACT_B*1*time_sampling;
    }
  	//Brake if too much speed; else keep controlling;
    else if (vehicle_status->vehicle_speed > Speed*SPEED_TOLERANCE){
    	 accel = 0;
    	 brake = brake - SPEED_REACT_B*error_speed*time_sampling;
    }
    else{
    	 accel = accel*distance_factor + (SPEED_REACT_A_P*distance)*time_sampling;
    	 brake = 0;
    }
    //limits
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
    vehicle_status->brake_pedal_pos = brake;
    vehicle_status->gas_pedal_pos = accel;

    //Orientation
    double speed_factor; // Reduce steering in high speed
    speed_factor = exp(-SPEED_FACTOR*vehicle_status->vehicle_speed); 
    steering = (error_Y*cos(head) - error_X*sin(head))*speed_factor;
	//limits
	if (steering>100){
		steering = 100;
	} 
	if (steering<-100){
		steering = -100;
	}
	vehicle_status->steering_wheel_pos = steering;

    fprintf(dr,"%f,", time);
    fprintf(dr,"%f,", head);
    fprintf(dr,"%f,", head_aim);
    fprintf(dr,"%f\n", head_desired);

}