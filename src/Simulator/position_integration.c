#include "header.h"

void position_integration(double angle, 
							double velocity, 
							double time,
							struct VEHICLE_STATUS* vehicle){	
	
	double del_X;
	double del_Y;

	del_X = velocity*cos(angle);
	del_Y = velocity*sin(angle);
	vehicle->vehicle_position_X += del_X;
	vehicle->vehicle_position_Y += del_Y;

	}

