#include "ros/ros.h"
/*
    需要实现参数的删除：
        实现：ros::NodeHandle::deleteParam();
             ros::param::del();
        附：查看参数服务器中的参数： rosparam list
*/
int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    // 初始化ROS节点
    ros::init(argc, argv, "del_param_c");
    // 创建ROS节点句柄
    ros::NodeHandle nh;
    // 删除： NodeHandle
    bool flag1 = nh.deleteParam("radius");
    if (flag1){
        ROS_INFO("删除成功");
    }
    else{
        ROS_INFO("删除失败");
    }

    // 删除：ros::param
    bool flag2 = ros::param::del("radius_param");
    if (flag2){
        ROS_INFO("radius_param删除成功");
    }
    else{
        ROS_INFO("radius_param删除失败");
    }
    
    return 0;
}