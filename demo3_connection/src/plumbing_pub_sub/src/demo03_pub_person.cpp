#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"
/*
    发布方实现：发布人的消息
        1. 包含头文件: #include "plumbing_pub_sub/Person.h"
        2. 初始化ROS节点；
        3. 创建节点句柄；
        4. 创建发布者对象；
        5. 编写发布逻辑并发布数据
        6. 打印当前发布者发布的数据: rostopic echo xxxxxxtopic
*/
int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    ROS_INFO("这是消息的发布方: ");
    // 2. 初始化ROS节点；
    ros::init(argc, argv, "Teacher");
    // 3. 创建节点句柄；
    ros::NodeHandle nh;
    // 4. 创建发布者对象；
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("Teacher_Info", 10);
    // 5. 编写发布逻辑并发布数据
    // 5.1 创建被发布的数据
    plumbing_pub_sub::Person Teacher;
    Teacher.name = "班主任";
    Teacher.age = 30;
    Teacher.height = 1.8;
    // 5.2 设置发布频率
    ros::Rate rate(1);
    // 5.3 循环发布数据
    while(ros::ok){
        // 修改被发布的数据
        Teacher.age += 1;
        // 核心: 数据发布
        pub.publish(Teacher);
        ROS_INFO("发布的消息：%s, %d, %f", Teacher.name.c_str(), Teacher.age, Teacher.height);
        // 休眠
        rate.sleep();
        // 建议操作
        ros::spinOnce();
    }
    return 0;
}