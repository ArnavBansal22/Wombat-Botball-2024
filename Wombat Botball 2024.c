#include <kipr/wombat.h>

// wait_for_light(_);  <-- USE IN FINAL PROJECT
// shut_down_in(119);  <-- USE IN FINAL PROJECT

// Variables
    // Motors
        int left_motor_port = 3;
        int right_motor_port = 0;
        int left_motor_power = 70;
        int right_motor_power = 67;

    // Color Sensors
        int color_sensor_port = 0;
        int blackwhite_threshold = 3500; // CHANGE THIS AT COMPETITION

    // Servos
        int sorting_s = 3;
        int sorting_s_leftpos = 500; //CHANGE THIS
        int sorting_s_rightpos = 1500; //CHANGE THIS
        int arm_s = 0;
        int claw_s = 1;


// Basic Functions
    //drive forward for a certain time
        int drive_forward(int time) {
            motor(left_motor_port, left_motor_power);
            motor(right_motor_port, right_motor_power);
            msleep(time);
            ao();
            return(0);
        }

	//drive backward for a certain time
        int drive_backward(int time) {
            motor(left_motor_port, -1*left_motor_power);
            motor(right_motor_port, -1*right_motor_power);
            msleep(time);
            ao();
            return(0);
        }

    //drive forward until the next black line
       int drive_forward_until_black_line() {
            while (analog(color_sensor_port) <  blackwhite_threshold) {
                motor(left_motor_port, left_motor_power);
                motor(right_motor_port, right_motor_power);
            }
            ao();
            return(0);
        }

    // set sorting_s position to left
        int sorting_servo_left() { 
            enable_servos();
            set_servo_position(sorting_s, sorting_s_leftpos);
            msleep(500);
            disable_servos();
            return(0);
        }

    // set sorting_s position to right
        int sorting_servo_right() { 
            enable_servos();
            set_servo_position(sorting_s, sorting_s_rightpos);
            msleep(500);
            disable_servos();
            return(0);
        }

    // set arm_s position to a position
        int arm_servo_posfun(int arm_s_pos) {
            enable_servos();
            set_servo_position(arm_s, arm_s_pos);
            msleep(500);
            disable_servos();
            return(0);
        }

    // set claw_s position to a position
        int claw_servo_posfun(int claw_s_pos) { /* CHANGE THE NAME */
            enable_servos();
            set_servo_position(claw_s, claw_s_pos);
            msleep(500);
            disable_servos();
            return(0);
        }

    // turn robot left
        int turn_left(int time) {
            motor(left_motor_port, -1*right_motor_power);
            motor(right_motor_port, left_motor_power);
            msleep(time);
            ao();
            return(0);
        }

    // turn robot right
        int turn_right(int time) {
            motor(left_motor_port, right_motor_power);
            motor(right_motor_port, -1*left_motor_power);
            msleep(time);
            ao();
            return(0);
        }

int main()
{
    arm_servo_posfun(1300);
    claw_servo_posfun(1500);
    sorting_servo_left();
    drive_forward_until_black_line();
    drive_forward(2000);
    turn_left(1000);
    drive_forward(1000);
    return 0;
}
