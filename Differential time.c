#include <time.h>																		//contains function for getting time
#include <stdio.h>																		//contains function for basic input-output


double function(int *t)																	// declaration of function under consideration
    {
		int end_time = time(0);															//Getting current time
		double difference = end_time - *t;												//Calculating differnce
		*t = end_time;																	//setting time of last run, needed for rerurn	
		return difference;																//returning time diffference
	}


int main() 																				//start of main function
{
    int t = time(0);																	// set inital time; t0
    double time_differntial = 0; 														
    time_differntial = function(&t);													//Use of function
    printf("The time difference is %lf.\n", time_differntial);							//Outputng the difference
    return 0; 																			//declaring end of main function
}
