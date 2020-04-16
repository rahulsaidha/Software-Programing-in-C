
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


#include<stdio.h>
#include <math.h> 
#define PI 3.14

void function(double angle, double velocity, double time);

int main()
{
	double vehicle_angle, vehicle_angle_radian, vehicle_velocity, vehicle_time;
	printf("The maximum accuracy to six digits after decimal point, take that into consideration\n");
	printf("Enter the angle at which vehicle is moving in degrees ");
	scanf("%lf", &vehicle_angle);
	printf("Enter the velocity at which vehicle is moving ");
	scanf("%lf", &vehicle_velocity);
	printf("Enter the time for which vehicle is moving ");
	scanf("%lf", &vehicle_time);
	printf("The angle at which vehicle is moving is %lf degree and the velocity of vehicle is %lf.\n", vehicle_angle, vehicle_velocity);
	vehicle_angle_radian = vehicle_angle * PI / 180;														
	function(vehicle_angle_radian, vehicle_velocity, vehicle_time);
	return 0;
	}
	
void function(double angle, double velocity, double time)
{
	double x,y;
	x = (velocity)*(cos(angle))*(time);
	y = (velocity)*(sin(angle))*(time);
	printf("The position of vehicle is ( %lf, %lf). cos() is %lf sin() is %lf\n", x ,y, cos(angle), sin(angle));
	}

