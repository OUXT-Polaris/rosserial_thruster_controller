#include "mbed.h"
#include <ros.h>
#include <std_msgs/Float32.h>

//タイムアウト(ms)
#define TIMEOUT_MS 1000 

Timer Timeout_timer;

ros::NodeHandle  nh;
// // PWM信号の差動出力ピンを指定
// PwmOut motor_P(p26);
// // PWM信号の差動出力 ピンを指定
// PwmOut motor_N(p25);
// PWM信号の差動出力ピンを指定
PwmOut motor_P(LED1);
// PWM信号の差動出力 ピンを指定
PwmOut motor_N(LED2);
DigitalOut ROS_sub_status(LED4);

void messageCb(const std_msgs::Float32& msg) {

    motor_P = (0.5 - (msg.data/2.0));
    motor_N = (0.5 + (msg.data/2.0));
    Timeout_timer.reset();
    ROS_sub_status = !ROS_sub_status;
}

ros::Subscriber<std_msgs::Float32> sub("/right_thrust_cmd", messageCb);
int main() {
    ROS_sub_status = 0;
    Timeout_timer.start();
    nh.initNode();
    nh.subscribe(sub);

    while (1) {
        if(Timeout_timer.read_ms() > TIMEOUT_MS){
            motor_P = 0.5;
            motor_N = 0.5;
        }
        nh.spinOnce();
    }
}
