#include "header.h"
																	
double differential_time(void){
	static time_t last_time_call = time(NULL);									
	double differencial_time;
	differencial_time = difftime(time(NULL), last_time_call);	
	last_time_call = time(NULL);							
	return differencial_time;	
}																

