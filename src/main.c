/*Main routine*/

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