void controller(struct VEHICLE_STATUS *vehicle_status);
void gas_pedal_sensor(struct VEHICLE_STATUS *vehicle_status);
void brake_pedal_sensor(struct VEHICLE_STATUS *vehicle_status);
void steering_wheel_sensor(struct VEHICLE_STATUS *vehicle_status);
void wheel_sensor(struct VEHICLE_STATUS *vehicle_status);
void direction_actuator(struct VEHICLE_STATUS *vehicle_status);
void fuel_actuator(struct VEHICLE_STATUS *vehicle_status);
void brake_actuator(struct VEHICLE_STATUS *vehicle_status);
    //range_sensor(vehicle_status); release 3
    //vision_sensor(vehicle_status); release 3
/*
double differential_time(void);
void vehicle_angle(vehicle_status,*time_sampling);
void motor_rotation(vehicle_status,*time_sampling);
void vehicle_velocity(vehicle_status,*time_sampling);
void position_integration(vehicle_status,*time_sampling);
void driver_attitude(vehicle_status);
    // environment_status(vehicle_status); release 3
void information_display(vehicle_status);
*/