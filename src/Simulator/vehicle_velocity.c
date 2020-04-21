/** 
* The function calculates the speed of the vehicle based on the rotation of *the wheel.
* @param[in]: time_sampling 
* @param[in]: *vehicle actions from the driver in vehicle_status that affect the motor
* @param[out]: *vehicle speed of the vehicle updated. 
*/



#include "header.h"

/* Internal Parameters */
#define POWER_MOTOR 0.1
#define	POWER_BRAKE 0.005
#define DYNAMIC_FRICTION 0.1

void vehicle_velocity(double time_sampling, struct VEHICLE_STATUS* vehicle){
	double speed;
	double accel = 0;
	double motor;
	double brake;
	double static_friction;

	motor = vehicle->fuel_actuator_pos;
	brake = vehicle->brake_actuator_pos;
	speed = vehicle->vehicle_speed;

	/* Vehicle's dynamic equation */
	accel = motor*POWER_MOTOR - brake*POWER_BRAKE*speed - DYNAMIC_FRICTION*speed;
	speed += accel*time_sampling;
	vehicle->vehicle_wheel_rotation = speed/(0.5*PI);

	vehicle->vehicle_speed = speed;																											
	}
