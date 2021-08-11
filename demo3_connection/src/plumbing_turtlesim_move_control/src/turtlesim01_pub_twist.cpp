#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
/*
    需求： 发布速度消息
        话题： /turtle1/cmd_vel(可以通过rostopic list + rqt_graph的方式确定话题是什么)
        消息载体： geometry_msgs/Twist
        消息格式：rosmsg info geometry_msgs/Twist
                geometry_msgs/Vector3 linear
                float64 x
                float64 y
                float64 z
                geometry_msgs/Vector3 angular
                float64 x
                float64 y
                float64 z
    
    1. 包含头文件；
    2. 初始化ROS节点；
    3. 创建节点句柄；
    4. 创建发布对象；
    5. 组织发布逻辑；
    6. spinOnce();
*/

int main(int argc, char *argv[]){
    // 2. 初始化ROS节点；
    ros::init(argc, argv, "turtle_control");
    // 3. 创建节点句柄；
    ros::NodeHandle nh;
    // 4. 创建发布对象；
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    // 5. 组织发布逻辑；
    ros::Rate rate(10); // 设置发布频率
    // 组织被发布的消息
    geometry_msgs::Twist twist;
    twist.linear.x = 1.0;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;
    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 0.5;
    // 循环发布消息
    while(ros::ok()){
        pub.publish(twist);
        // 休眠，只有休眠了才能以10Hz的速度进行消息发布
        rate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}