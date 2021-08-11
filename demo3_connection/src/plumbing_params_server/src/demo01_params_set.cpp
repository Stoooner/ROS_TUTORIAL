#include "ros/ros.h"

/*
    需要实现参数的新增与修改：
        1. 设置机器人的共享参数，类型、半径(0.15m)，再修改半径(0.2m)，；
        2. 实现：ros::NodeHandle::setParam("key", "value")
                ros::param::set("key", "value")
*/

int main(int argc, char *argv[]){
    // 初始化ROS节点
    ros::init(argc, argv, "set_param_c");
    // 创建ROS节点句柄
    ros::NodeHandle nh;
    // 参数增
    // 方案1：nh
    nh.setParam("type", "xiaohuangche");
    nh.setParam("radius", 0.15);
    // 方案2：ros::param
    ros::param::set("type_param", "xiaobai");
    ros::param::set("radius_param", 0.15);
    // 参数改
    // 方案1：nh--->在键值一致的情况下，其实就是新的值对旧的值进行了覆盖从而完成了修改
    nh.setParam("radius", 0.2);
    // 方案2：ros::param
    ros::param::set("radius_param", 0.7);
    return 0;
}