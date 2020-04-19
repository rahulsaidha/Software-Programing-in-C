#include "header.h"

double differential_time(int *t)																	
    {
		int end_time = time(0);															
		double difference = end_time - *t;																										
		return difference;																
	}

double automatic_brake(double velocity, double acceleration, double angle)
{
	double vehicle_head_position = 0, brake = 0, vehicle_velocity = 0, vehicle_angle = 0, vehcile_acceleration = 0;
	int debri = 0, t = time(0);
	//int i = 1000000;
	do
	{
		double difference = function(&t);
		vehicle_head_position = (velocity * difference) + (0.5 * acceleration * difference *difference);
		//i--;
		printf("head : %lf, difference : %lf, velocity : %lf \n", vehicle_head_position, difference, velocity);
		//if(i == 0(Put the condition to check debri))																		
			//debri = 1;																									
		} while(debri == 0);
}
{
	double vehicle_velocity = 0, vehicle_angle = 0, vehicle_acceleration = 0;
	automatic_brake(vehicle_velocity, vehicle_acceleration, vehicle_angle);
	return 0;
	}
	
