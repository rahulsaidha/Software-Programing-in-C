/*Main routine


*/
#include "header.h"
#include "main.h"

void simulator(struct VEHICLE_STATUS *vehicle_status) {
	static double total_time = 0;
	double *time_sampling;
	*time_sampling = differential_time();
	total_time = total_time + *time_sampling;
    vehicle_angle(vehicle_status,*time_sampling);
    motor_rotation(vehicle_status,*time_sampling);
    vehicle_velocity(vehicle_status,*time_sampling);
    position_integration(vehicle_status,*time_sampling);
    driver_attitude(vehicle_status);
    // environment_status(vehicle_status); release 3
    information_display(vehicle_status);
}

void system(struct VEHICLE_STATUS *vehicle_status) {
    controller(vehicle_status);
    gas_pedal_sensor(vehicle_status);
    brake_pedal_sensor(vehicle_status);
    steering_wheel(vehicle_status);
    wheel_sensor(vehicle_status);
    direction_actuator(vehicle_status);
    fuel_actuator(vehicle_status);
    //range_sensor(vehicle_status); release 3
    //vision_sensor(vehicle_status); release 3
}
    
int main(void)
{
    VEHICLE_STATUS *vehicle_status;
    vehicle_status = (struct VEHICLE_STATUS*) malloc(sizeof(struct VEHICLE_STATUS));
    int iteration = 10; //TEMP
    while (1) {
        simulator(vehicle_status);
        system(vehicle_status);

        /*This brake condition is development only
        and will be changed to the final break condition
        as soon as we define it.
        */
        
        if (iteration < 1) {
            break;
        }
        iteration--;
    }
}