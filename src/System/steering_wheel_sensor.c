#include "header.h"

void steering_wheel_sensor(struct VEHICLE_STATUS *vehicle_status){
	if(vehicle_status->Comm_bus_address == STEERING_SSR_ADDRESS){
		vehicle_status->Comm_bus_message = vehicle_status->steering_wheel_pos;
		vehicle_status->Comm_bus_address = CTRL_ADDRESS;
	}
}