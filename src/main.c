/*Main routine*/
#include <stdio.h>

// Bus Addresses:
#define   CTRL_ADDRESS    	    	= 10001010
#define   GAS_PEDAL_SSR_ADDRESS		= 10000001
#define   BRAKE_PEDAL_SSR_ADDRESS	= 10000010
#define   STEERING_SSR_ADDRESS    	= 10000011
#define   WHEEL_SSR_ADDRESS             = 10000100
#define   DIR_ACT_ADDRESS		= 10000101
#define   FUEL_ACT_ADDRESS		= 10000110
#define   BRAKE_ACT_ADDRESS		= 10000111
}

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
};

void simulator(void) {
    differential_time();
    vehicle_angle();
    motor_rotation();
    vehicle_velocity();
    position_integration();
    driver_attitude();
    // environment_status(); release 3
    information_display();
}

void system(void) {
    controller();
    gas_pedal_sensor();
    brake_pedal_sensor();
    steering_wheel();
    wheel_sensor();
    direction_actuator();
    fuel_actuator();
    //range_sensor(); release 3
    //vision_sensor(); release 3
}
    
int main(void)
{
    VEHICLE_STATUS vehicle_status;
    int iteration = 10; //TEMP
    while (1) {
        simulator();
        system();

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