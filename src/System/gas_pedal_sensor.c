#include "header.h"

void gas_pedal_sensor(struct VEHICLE_STATUS *vehicle_status){
	if(vehicle_status->Comm_bus_address == GAS_PEDAL_SSR_ADDRESS){
		vehicle_status->Comm_bus_message = vehicle_status->gas_pedal_pos;
		vehicle_status->Comm_bus_address = CTRL_ADDRESS;
	}
}