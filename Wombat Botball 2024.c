#include <kipr/wombat.h>

// wait_for_light(_);  <-- USE IN FINAL PROJECT
// shut_down_in(119);  <-- USE IN FINAL PROJECT

// 0 = FALSE
// 1 = TRUE

// Variables
int left_motor_port = 3;
int right_motor_port = 0;
int left_motor_power = 70;
int right_motor_power = 67;
int color_sensor_port = 1;
int blackwhite_threshold = 1500;
int /* CHANGE THIS */ condition_1 = 0;
int servo_arm1_port = 0;
int servo_arm1_upposition = 600; //CHANGE THIS
int servo_arm1_downposition = 1200; //CHANGE THIS

// Other basic Functions
    //drive forward for a certain time
        int drive_forward(int time) {
            motor(left_motor_port, left_motor_power);
            motor(right_motor_port, right_motor_power);
            msleep(time);
            ao();
            return(0);
        };

    //drive forward until the next black line
        int drive_forward_until_black_line() {
            while (analog(color_sensor_port) < blackwhite_threshold) {
                motor(left_motor_port, left_motor_power);
                motor(right_motor_port, right_motor_power);
                
            }
            ao();
            return(0);
        }
    
    //line follower (follow a black line)  
        int follow_black_line() {
            while (condition_1 == 0) {
                if (analog(color_sensor_port) > blackwhite_threshold) { // on black, go to white
                    motor(right_motor_port, right_motor_power);
                    motor(left_motor_port, 0);
                }
                if (analog(color_sensor_port) > blackwhite_threshold) { // on white, go to black
                    motor(left_motor_port, left_motor_power);
                    motor(right_motor_port, 0);
                }
            }
            ao();
            return(0);
        }

    // set servo position to open/up
        int open_claw() { /* CHANGE THE NAME */
            enable_servos();
            set_servo_position(servo_arm1_port, servo_arm1_upposition);
            msleep(500);
            disable_servos();
            return(0);
        }
    
    // set servo position to closed/down
        int close_claw() { /* CHANGE THE NAME */
            enable_servos();
            set_servo_position(servo_arm1_port, servo_arm1_downposition);
            msleep(500);
            disable_servos();
            return(0);
        }
    
    // turn robot left
        int turn_left(int time) {
            motor(left_motor_port, 0);
            motor(right_motor_port, left_motor_power);
            msleep(time);
            ao();
            return(0);
        }

    // turn robot right
        int turn_right(int time) {
            motor(left_motor_port, left_motor_power);
            motor(right_motor_port, 0);
            msleep(time);
            ao();
            return(0);
        }
