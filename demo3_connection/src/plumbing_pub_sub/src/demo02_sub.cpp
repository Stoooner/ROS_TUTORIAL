#include "ros/ros.h"
#include "std_msgs/String.h"
/*
    订阅方实现：
        1. 包含头文件: ROS中的文本类型--->std_msgs/String.h
        2. 初始化ROS节点；
        3. 创建节点句柄；
        4. 创建订阅者对象；
        5. 处理订阅数据；
        6. spin()函数；
*/

// std_msgs::String::ConstPtr是String类型的常量指针
void handleMsg(const std_msgs::String::ConstPtr &msg){
    // 通过msg获取并操作订阅到数据
    ROS_INFO("subscriber get info: %s", msg->data.c_str());
}

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    // 2. 初始化ROS节点；
    ros::init(argc, argv, "info_subscriber");
    // 3. 创建节点句柄；
    ros::NodeHandle nh;
    // 4. 创建订阅者对象；
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("house", 10, handleMsg);
    // 5. 处理订阅数据；
    ros::spin(); // spin()的作用是让函数执行到此处后返回去执行回调函数handleMsg，因为回调函数handleMsg需要被频繁执行
    return 0;
}