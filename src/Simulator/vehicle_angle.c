#include "header.h"

void vehicle_angle(double velocity, 
					double time_sampling, 
					struct VEHICLE_STATUS* vehicle){
	double wheel_angle;
	wheel_angle = vehicle->direction_actuator_pos*(PI/100);
	vehicle->vehicle_wheel_angle = wheel_angle;
	vehicle->vehicle_angle += wheel_angle*velocity*time_sampling;
	/* limits -PI to PI */
	if(vehicle->vehicle_angle>PI){
		vehicle->vehicle_angle -= 2*PI;
	} 	
	if(vehicle->vehicle_angle<(-PI)){
		vehicle->vehicle_angle += 2*PI;
	}
}
	