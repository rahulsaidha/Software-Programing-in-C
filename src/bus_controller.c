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

float bus_controller(void) {
    
    // Variables for bus controlling
    static int device = 1; // Controls which device should be accessed by controller
    device++;
    if (device > 9) {
        device = 1
    }
    // Choose device to be accessed
    switch (device) {
        case 1:
            return GAS_PEDAL_SSR_ADDRESS;
        case 2:
            return BRAKE_PEDAL_SSR_ADDRESS;
        case 4:
            return STEERING_SSR_ADDRESS;
        case 5:
            return WHEEL_SSR_ADDRESS;
        case 6:
            return DIR_ACT_ADDRESS;
        case 7:
            return FUEL_ACT_ADDRESS;
        case 8:
            return BRAKE_ACT_ADDRESS;
        }
    }
}

void main() {
    int address = bus_controller();
}