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
        注意：由于这里是改变了键盘控制，而键盘控制与乌龟GUI之间是话题通信，其中键盘控制是发布者，乌龟GUI是订阅者，
             因此这里直接实现发布者的内容改写即可，因此这个改变乌龟运动轨迹的例子里只有话题发布者，因为订阅者乌龟GUI
             官方已经实现了。
    
    1. 包含头文件；
    2. 初始化ROS节点；
    3. 创建节点句柄；
    4. 创建发布对象；
    5. 组织发布逻辑；
    6. spinOnce();
*/

int main(int argc, char *argv[]){
    // 2. 初始化ROS节点；
    ros::init(argc, argv, "turtle_move_control_publisher");
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