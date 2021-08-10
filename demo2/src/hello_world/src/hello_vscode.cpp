#include "ros/ros.h"

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "hello");
    ROS_INFO("hello, 这是ros教程!!!!!");
    return 0;
}