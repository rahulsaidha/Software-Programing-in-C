#include "header.h"

void wheel_sensor(struct VEHICLE_STATUS *vehicle_status){
	if(vehicle_status->Comm_bus_address == WHEEL_SSR_ADDRESS){
		vehicle_status->Comm_bus_message = vehicle_status->vehicle_wheel_rotation;
		vehicle_status->Comm_bus_address = CTRL_ADDRESS;
	}
}