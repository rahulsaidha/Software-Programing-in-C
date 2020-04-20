#include "header.h"

#ifndef BODY_FACTOR
#define BODY_FACTOR 0.1
#endif

void vehicle_angle(double time_sampling, struct VEHICLE_STATUS* vehicle){
	double wheel_angle;
	wheel_angle = vehicle->direction_actuator_pos*(PI/200);
	vehicle->vehicle_wheel_angle = wheel_angle;
	vehicle->vehicle_angle += wheel_angle*vehicle->vehicle_speed*BODY_FACTOR*time_sampling;
	/* limits -PI to PI */
	if(vehicle->vehicle_angle>PI){
		vehicle->vehicle_angle -= 2*PI;
	} 	
	if(vehicle->vehicle_angle<(-PI)){
		vehicle->vehicle_angle += 2*PI;
	}
}
	