
// Factorial
/*

	double fact(int number)
	{
		double factorial = 1;
		for(int i = 1; i <= number; i++)
		{
			factorial = factorial * i;
		}
		return factorial;
	}

 
// Power function


	double power(int n, int number)
	{
		double power = 1;
		for(int i = 1; i <= n; i++)
		{
			power = power * number;
		}
		return power;
	}


//COS function


	double cos(double angle)
	{
		double cos = 0;
		for(int n = 0; n <= 100; n++)
		{
			cos = cos + (power(n, -1))*(power(2*n, angle))/fact(2*n);
		}
		return cos;
	}  
	


//SIN function


	double sin(double angle)
	{
		double sin = 0;
		for(int n = 0; n <= 100; n++)
		{
			sin = sin + (power(n, -1))*(power(2*n + 1, angle))/fact(2*n + 1);
		}
		return sin;
	} 

*/


#include "header.h"
#define PI 3.14

double position_integration  (double angle, double velocity, double time);
{
	double vehicle_angle, vehicle_angle_radian, vehicle_velocity, vehicle_time;
	
	vehicle_angle_radian = vehicle_angle * PI / 180;											
	function(vehicle_angle_radian, vehicle_velocity, vehicle_time);
	return 0;
	}
	
double position_integration(double angle, double velocity, double time)
{
	double x,y;
	x = (velocity)*(cos(angle))*(time);
	y = (velocity)*(sin(angle))*(time);
	}

