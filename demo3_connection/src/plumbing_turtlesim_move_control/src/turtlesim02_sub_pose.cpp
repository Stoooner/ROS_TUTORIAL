#include "ros/ros.h"
#include "turtlesim/Pose.h"

/*
    需求：订阅乌龟的位姿信息，并输出到控制台
    1. 包含头文件, 导包
    2. 初始化ROS节点
    3. 创建节点句柄
    4. 创建节点对象
    5. 处理订阅数据(由于订阅到的数据不知道什么时候过来，因为需要使用回调函数)
    6. spin()函数
    需要注意的是在这个接收乌龟位姿的例子里，乌龟GUI和位姿是话题通信，且位姿是订阅者，因此只需要实现订阅者即可
    注意：
        坐标点是相对于坐标系而言的，在乌龟GUI中坐标系中心点是在图像左下角的，横向是x轴，纵向是y轴
*/

// 处理订阅到的数据的回调函数
void handlePose(const turtlesim::Pose::ConstPtr &pose_info){
    ROS_INFO("乌龟的位姿信息: 坐标(x=%.2f, y=%.2f), 朝向(%.2f), 线速度:%.2f, 角速度: %.2f",
              pose_info->x, pose_info->y, pose_info->theta, 
              pose_info->linear_velocity,
              pose_info->angular_velocity);
}

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    // 2. 初始化ROS节点
    ros::init(argc, argv, "turtle_pose_subscriber");
    // 3. 创建节点句柄
    ros::NodeHandle nh;
    // 4. 创建节点对象(这里的订阅者函数可以根据回调自动推到出泛型/模板，因此可以不用写泛型/模板，但是如果是发布者的话需要在发布函数上写泛型/模板)
    ros::Subscriber sub = nh.subscribe("/turtle1/pose", 100, handlePose);
    // 5. 处理订阅数据(由于订阅到的数据不知道什么时候过来，因为需要使用回调函数)
    // 6. spin()函数
    ros::spin();
    return 0;
}