#include "header.h"

#define PI 3.142

double vehicle_angle ()		
{
	double vehicle_angle;
	vehicle_angle = asin((vehicle_altitude/(vehicle_velocity*time))) * 180 / PI;		
	double vehicle_velocity, vehicle_altitude, time;
	function(vehicle_velocity, vehicle_altitude, time);									
	return vehicle angle;
}
	