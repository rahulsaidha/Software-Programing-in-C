/*Bus Controller
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

int bus_controller(struct VEHICLE_STATUS *vehicle_status,double steering_wheel_pos,
                                                        double gas_pedal_pos,
                                                        double brake_pedal_pos) {
    
    // Variables for bus controlling
    static int device = 1; // Controls which device should be accessed by controller
    device++;
    if (device > 9) {
        device = 1
    }
    // Choose device to be accessed
    switch (device) {
        case 1:             
            vehicle_status->Comm_bus_address = GAS_PEDAL_SSR_ADDRESS;
            vehicle_status->Comm_bus_message = 1;
            return GAS_PEDAL_SSR_ADDRESS;
        case 2:
            vehicle_status->Comm_bus_address = BRAKE_PEDAL_SSR_ADDRESS;
            vehicle_status->Comm_bus_message = 1;
            return BRAKE_PEDAL_SSR_ADDRESS;
        case 4:            
            vehicle_status->Comm_bus_address = STEERING_SSR_ADDRESS;
            vehicle_status->Comm_bus_message = 1;
            return STEERING_SSR_ADDRESS;
        case 5:
            vehicle_status->Comm_bus_address = WHEEL_SSR_ADDRESS;
            vehicle_status->Comm_bus_message = 1;
            return WHEEL_SSR_ADDRESS;
        case 6:
            vehicle_status->Comm_bus_address = DIR_ACT_ADDRESS;
            vehicle_status->Comm_bus_message = steering_wheel_pos;
            return DIR_ACT_ADDRESS;
        case 7:
            vehicle_status->Comm_bus_address = FUEL_ACT_ADDRESS;
            vehicle_status->Comm_bus_message = gas_pedal_pos;
            return FUEL_ACT_ADDRESS;
        case 8:
            vehicle_status->Comm_bus_address = BRAKE_ACT_ADDRESS;
            vehicle_status->Comm_bus_message = brake_pedal_pos;
            return BRAKE_ACT_ADDRESS;
    }
}


void main() {
    int address = bus_controller();
}