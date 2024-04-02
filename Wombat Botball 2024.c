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
int color_sensor_port = 0;
int blackwhite_threshold = 1500;
// int /* CHANGE THIS */ condition_1 = 0;
int sorting_servo = 3;
int sorting_servo_leftpos = 500; 
int sorting_servo_rightpos = 1500;
int arm_servo = 0;
int claw_servo = 1;

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
    /*    int follow_black_line() {
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
        } */

    // set sorting_servo position to left
        int sorting_servo_left() { /* CHANGE THE NAME */
            enable_servos();
            set_servo_position(sorting_servo, sorting_servo_leftpos);
            msleep(500);
            disable_servos();
            return(0);
        }
    
    // set sorting_servo position to right
        int sorting_servo_right() { /* CHANGE THE NAME */
            enable_servos();
            set_servo_position(sorting_servo, sorting_servo_rightpos);
            msleep(500);
            disable_servos();
            return(0);
        }
    
    // set arm_servo position to a position
        int arm_servo_posfun(int arm_servo_pos) { /* CHANGE THE NAME */
            enable_servos();
            set_servo_position(arm_servo, arm_servo_pos);
            msleep(500);
            disable_servos();
            return(0);
        }

    // set claw_servo position to a position
        int claw_servo_posfun(int claw_servo_pos) { /* CHANGE THE NAME */
            enable_servos();
            set_servo_position(claw_servo, claw_servo_pos);
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

int main() {

}

