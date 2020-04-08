#include <stdio.h>

#define PI 3.142

void function(double radius, double rotation, double time)																// Defination of function
{
	double cirumference = 2 * PI * radius;																				// Calculating circumference of wheel
	double distance = cirumference * rotation;																			// Calculating distance travelled by vehicle
	double velocity = distance / time;																					// Calculating velocity
	printf("The velocity of vehicle whose wheels turned %lf in time %lf seconds is %lf.\n", rotation, time, velocity);	// Outputting the information
	}
	
int main()																												// Start of main function
{
	double radius = 0, rotation = 0, time = 0;																			// Initalization of variables
	printf("Enter the radius of the vehicle's wheel in meter: ");
	scanf("%lf", &radius);																								// Taking radius of wheel
	printf("Enter the number of rotation of wheel of vehicle: ");
	scanf("%lf", &rotation);																							// Taking number of rotations
	printf("Enter the time for which vehicle has travelled in seconds: ");
	scanf("%lf", &time);																								// Taking time for which vehicle has travelled
	function(radius, rotation, time);																					// Use of function
	return 0;																											// End Of Program
	}
