/*driver_attitude
This function simulates the behaviour of a driver driving the vehicle.
It acts on the steering wheel, gas pedal and brake pedal in trying to follow the position (called aim) given by the trajectory file.
The aim is the moving position X and Y stored in the file. The function pass commands to the vehicle that is mimics the behaviour of a driver.
*/
#include "header.h"

#define SPEED_TOLERANCE 1.15 // Threshold for brake
#define SPEED_REACT_A 0.1 // How agressive it accelerates
#define SPEED_REACT_B 0.9 // How agressive it brakes
#define ATT_REACT 0.1 // How fast steering whell moves

void driver_attitude(double time_sampling, FILE *trjc, struct VEHICLE_STATUS *vehicle_status){

	// Parsing .csv file 
	char line[1000];
	char *value;
	char *eptr;
    fgets(line,1000,trjc);
    value = strtok(line, ",");
    double time = strtod(value, &eptr);
    value = strtok(NULL, ",");
    double X = strtod(value, &eptr);
    value = strtok(NULL, ",");
    double Y = strtod(value, &eptr);
    value = strtok(NULL, ",");
    double Speed = strtod(value, &eptr);
    
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
    double speed_factor; //How far position is from the goal
    error_X = vehicle_status->vehicle_position_X - X;
    error_Y = vehicle_status->vehicle_position_Y - Y;
    speed_factor = sqrt((error_X*error_X) + (error_Y*error_Y)); //L2 norm of error vector
    head = atan2(vehicle_status->vehicle_position_X - last_real_X, (vehicle_status->vehicle_position_Y - last_real_Y) + 0.000001);
	head_desired = atan2(X - last_desired_X,(Y - last_desired_Y) + 0.000001);
	head_aim = atan2(error_X,(error_Y + 0.000001));
    error_head = (head - head_desired);
    error_aim = (head - head_aim);
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
    //Brake if vehicle is ahead of the aim
    if((abs(error_head) < 0.17) && (abs(error_aim) > 0.30)){
    	 accel = 0;
    	 brake = brake + SPEED_REACT_B*error_speed*time_sampling;
    }
  	//Brake if too much speed; else keep controlling;
    if (vehicle_status->vehicle_speed > Speed*SPEED_TOLERANCE){
    	 accel = 0;
    	 brake = brake - SPEED_REACT_B*error_speed*time_sampling;
    }
    else{
    	 accel = accel + SPEED_REACT_A*speed_factor*error_speed*time_sampling;
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
    double steering = vehicle_status->steering_wheel_pos;
    steering = steering + ATT_REACT*(head - head_aim)*time_sampling;
	//limits
	if (steering>100){
		steering = 100;
	} 
	if (steering<-100){
		steering = -100;
	}
	vehicle_status->steering_wheel_pos = steering;
}