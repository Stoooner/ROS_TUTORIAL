#include "ros/ros.h"
#include "turtlesim/Spawn.h"

/*
    需求：向服务器端(乌龟GUI的ROS节点)发送请求，在指定位置生成新的乌龟
    话题：/spawn
    消息：/turtlesim/Spawn

    1. 包含头文件, 导包
    2. 初始化ROS节点
    3. 创建节点句柄
    4. 创建客户端的节点对象
    5. 组织数据并发送
    6. 处理响应
*/

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    // 2. 初始化ROS节点
    ros::init(argc, argv, "turtle_spawn_client");
    // 3. 创建节点句柄
    ros::NodeHandle nh; 
    // 4. 创建客户端的节点对象
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    // 5. 组织数据并发送
    // 5.1 组织请求数据
    turtlesim::Spawn spawn_info;
    spawn_info.request.x = 1.0;
    spawn_info.request.y = 4.0;
    spawn_info.request.theta = 1.57;
    spawn_info.request.name = "turtle2";
    // 5.2 发送请求
    // 判断服务器是否开启
    // ros::service::waitForService("/spawn");
    client.waitForExistence();
    // flag用于接收响应状态，响应结果会被存储进spawn_info对象中
    bool flag = client.call(spawn_info);
    // 6. 处理响应
    if (flag){
        ROS_INFO("乌龟生成成功，新乌龟叫：%s", spawn_info.response.name.c_str());
    }else{
        ROS_INFO("请求失败!");
    }
    return 0;
}