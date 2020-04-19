#include "header.h"

void brake_pedal_sensor(struct VEHICLE_STATUS *vehicle_status){
	if(vehicle_status->Comm_bus_address == BRAKE_PEDAL_SSR_ADDRESS){
		vehicle_status->Comm_bus_message = vehicle_status->brake_pedal_pos;
		vehicle_status->Comm_bus_address = CTRL_ADDRESS;
	}
}