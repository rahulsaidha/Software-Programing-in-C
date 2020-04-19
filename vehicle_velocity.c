#include "header.h"

#define PI 3.142

double vehicle_velocity(double radius, double rotation, double time)																 
{
	double cirumference = 2 * PI * radius;																				
	double distance = cirumference * rotation;																			 
	double velocity = distance / time;																					

	double radius = 0, rotation = 0, time = 0;																		
	function(radius, rotation, time);																					
	return 0;																											
	}
