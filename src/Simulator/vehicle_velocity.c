#include "header.h"

#define POWER_MOTOR 0.6
#define	POWER_BRAKE 1.0
#define DYNAMIC_FRICTION 1.0

double vehicle_velocity(double time_sampling, struct VEHICLE_STATUS* vehicle){
	double speed = 0;
	double accel = 0;
	double motor;
	double brake;
	double static_friction;

	motor = vehicle->fuel_actuator_pos;
	brake = vehicle->brake_actuator_pos;

	/* Vehicle's dynamic equation */
	accel = motor*POWER_MOTOR - brake*POWER_BRAKE - DYNAMIC_FRICTION*speed;
	speed += accel*time_sampling;

	return speed;																											
	}
