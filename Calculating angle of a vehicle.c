#include <stdio.h>
#include <math.h>

#define PI 3.142

void function(double vehicle_velocity, double vehicle_altitude, double time)			// The function to calculate angle at which vehicle is
{
	double vehicle_angle;
	vehicle_angle = asin((vehicle_altitude/(vehicle_velocity*time))) * 180 / PI;		// Calculation of vehicle_angle in degrees
	printf("The angle at which angle is at is %lf.\n", vehicle_angle);					// Printing the value
	}

int main()
{
	double vehicle_velocity, vehicle_altitude, time;
	printf("Enter the Vehicle velocity: \n");
	scanf("%lf", &vehicle_velocity);													// Taking the vehicle velocity
	printf("Enter the Vehicle altitude: \n");
	scanf("%lf", &vehicle_altitude);													// Taking the vehicle altitude
	printf("Enter the time vehicle travelled for: \n");
	scanf("%lf", &time);																// Taking the time travelled
	function(vehicle_velocity, vehicle_altitude, time);									// Calculating angle with function
	return 0;																			// End Of Program
	}
