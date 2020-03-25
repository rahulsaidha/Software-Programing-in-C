/*Controller
  Bus Addresses:
  Controller            = 10001010
  gas_pedal_sensor      = 10000001
  brake_pedal_sensor    = 10000010
  steering_wheel_sensor = 10000011
  wheel_sensor          = 10000100
  direction_actuator    = 10000101
  fuel_actuator         = 10000110
  brake_actuator        = 10000111
  range_sensor - release 3
  vision_sensor - release 3
*/
#include <stdio.h>

void controller(void) {
    // List of system variables that the controller should
    // keep track of. These information are provided by the 
    // devices.
    static double vehicle_wheel_rotation;
    static double gas_pedal_pos;
    static double brake_pedal_pos;
    static double steering_wheel_pos;
    static double direction_actuator_pos;
    static double fuel_actuator_pos;
    static double brake_actuator_pos;
    //double range_sensor_val;
    //double vision_system_val;

    // Variables for system controlling
    static int last_bus_address;
    static int activity; // Controls which ativity should be performed by controller
 
    // Variable for bus reading/writing
    int Comm_bus_address = vehicle_status.Comm_bus_address;
    float Comm_bus_message; = vehicle_status.Comm_bus_message;
    
    // Treat information and store in the controller's memory
    if (Comm_bus_address == CTRL_ADDRESS) {
        switch (last_bus_address) {
        case GAS_PEDAL_SSR_ADDRESS:
            gas_pedal_pos = Comm_bus_message;
            break;
        case BRAKE_PEDAL_SSR_ADDRESS:
            brake_pedal_pos = Comm_bus_message;
            break;
        case STEERING_SSR_ADDRESS:
            steering_wheel_pos = Comm_bus_message;
            break;
        case WHEEL_SSR_ADDRESS:
            vehicle_wheel_rotation = Comm_bus_message;
            break;
        case DIR_ACT_ADDRESS:
            direction_actuator_pos = Comm_bus_message;
            break;
        case FUEL_ACT_ADDRESS:
            fuel_actuator_pos = Comm_bus_message;
            break;
        case BRAKE_ACT_ADDRESS:
            brake_actuator_pos = Comm_bus_message;
            break;
        }

    }

    last_bus_address = bus_controller();
	
	
    //watchdog_checker(); - release 2
    //health_checker(); - release 2
       
}

void main() {
    controller();
}