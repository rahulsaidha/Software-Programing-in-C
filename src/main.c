/*Main routine


*/
#include <stdio.h>

// Bus Addresses:
#define   CTRL_ADDRESS    	    	= 10001010
#define   GAS_PEDAL_SSR_ADDRESS		= 10000001
#define   BRAKE_PEDAL_SSR_ADDRESS	= 10000010
#define   STEERING_SSR_ADDRESS    	= 10000011
#define   WHEEL_SSR_ADDRESS         = 10000100
#define   DIR_ACT_ADDRESS			= 10000101
#define   FUEL_ACT_ADDRESS			= 10000110
#define   BRAKE_ACT_ADDRESS			= 10000111

struct VEHICLE_STATUS {
    double vehicle_wheel_angle;
    double vehicle_wheel_rotation;
    double vehicle_position_X;
    double vehicle_position_Y;
    double motor_rotation;
    double gas_pedal_pos;
    double brake_pedal_pos;
    double steering_wheel_pos;
    double direction_actuator_pos;
    double fuel_actuator_pos;
    double brake_actuator_pos;
    double range_sensor_val;
    double vision_system_val;

	int Comm_bus_address;
    float Comm_bus_message;
}

void simulator(struct VEHICLE_STATUS *vehicle_status) {
    differential_time(vehicle_status);
    vehicle_angle(vehicle_status);
    motor_rotation(vehicle_status);
    vehicle_velocity(vehicle_status);
    position_integration(vehicle_status);
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