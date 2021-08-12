#include "ros/ros.h"

/*
    修改参数服务器中turtlesim背景色相关的参数
        1. 初始化ROS节点
        2. 不一定需要创建节点句柄(和后续使用API有关)
        3. 修改参数
*/

int main(int argc, char *argv[])
{   
    // 1. 初始化ROS节点
    ros::init(argc,argv,"haha");
    // 2. 不一定需要创建节点句柄(和后续使用API有关)
    // /turtlesim/background_r中的/turtlesim称为命名空间，可以直接放在NodeHandle中来
    //ros::NodeHandle nh;
    ros::NodeHandle nh("turtlesim");
    nh.setParam("background_r",255);
    nh.setParam("background_g",255);
    nh.setParam("background_b",255);


    // 3. 修改参数
    // 3.1 如果调用ros::param::set不需要创建节点句柄
    // ros::param::set("/turtlesim/background_r", 0);
    // ros::param::set("/turtlesim/background_g", 0);
    // ros::param::set("/turtlesim/background_b",0);

    


    return 0;
}