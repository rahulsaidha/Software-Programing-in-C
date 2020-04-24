#include "header.h"
#include <string.h>
#include <time.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

double differential_time(void);

void print_results(FILE* fp,    int testcase, 
                                char comparison_1,                                
                                double expected_1,                                
                                double result_1,
                                char comparison_2,
                                double expected_2,
                                double result_2){
    printf("\nTestcase %d\n", testcase);
    printf("Expected: %c %f | Result: %f\n",comparison_1, expected_1, result_1);
    //printf("Expected: %c %f | Result: %f\n",comparison_2, expected_2, result_2); 
    fprintf(fp,"\nTestcase %d\n", testcase);
    fprintf(fp,"Expected: %c %f | Result: %f\n",comparison_1, expected_1, result_1);
    //fprintf(fp,"Expected: %c %f | Result: %f\n",comparison_2, expected_2, result_2); 
}

int main(void)
{
    VEHICLE_STATUS *vehicle;
    vehicle = (struct VEHICLE_STATUS*) malloc(sizeof(struct VEHICLE_STATUS));

    // Open Log file
    FILE *fp;
    char str[100];
    char* filename = "log.txt";
    fp = fopen(filename, "w");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    struct timespec tim;
    tim.tv_sec = 0.0;
    tim.tv_nsec = (1000000000.0)*0.999;

    int testcase = 0;
    double expect = 0.0;
    double time_sampling;

    /* Testcase 1 - Zero time on initialization;
    Expected: zero time */
    time_sampling = differential_time();
    print_results(fp, 1,'=',0.0,time_sampling,'=',0.0,0.0);

    /* Testcase 2 - Time in double execution; 
    Expected: close to zero time */
    time_sampling = differential_time();
    time_sampling = differential_time();
    print_results(fp, 2,'~',0.0,time_sampling,'=',0.0,0.0);

    /* Testcase 3 - Time after 0.01s of sleep; 
    Expected: 0.01 seconds passed */
    time_sampling = differential_time();
    tim.tv_sec = 0.0;
    tim.tv_nsec = (1000000000.0)*0.01;
    nanosleep(&tim, NULL);
    time_sampling = differential_time();
    print_results(fp, 3,'=',0.01,time_sampling,'=',0.0,0.0);

    /* Testcase 4 - Time after 0.99s of sleep; 
    Expected: 0.99s seconds passed */
    time_sampling = differential_time();
    tim.tv_sec = 0.0;
    tim.tv_nsec = (1000000000.0)*0.99;
    nanosleep(&tim, NULL);
    time_sampling = differential_time();
    print_results(fp, 4,'=',0.99,time_sampling,'=',0.0,0.0);

    /* Testcase 10 - Checking consistency over several calls; 
    Expected: 0.01 seconds passed */
    time_sampling = differential_time();
    tim.tv_sec = 0.0;
    tim.tv_nsec = (1000000000.0)*0.01;
    for (int i=0;i<50;i++){
        nanosleep(&tim, NULL);
        time_sampling = differential_time();
        print_results(fp,10,'=',0.01,time_sampling,'=',0.0,0.0);
    }

    printf("End of test\n");
    fclose(fp);
}