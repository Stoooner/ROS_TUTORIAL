#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
/*
    发布方实现：
        1. 包含头文件: ROS中的文本类型--->std_msgs/String.h
        2. 初始化ROS节点；
        3. 创建节点句柄；
        4. 创建发布者对象；
        5. 编写发布逻辑并发布数据
        6. 打印当前发布者发布的数据: rostopic echo xxxxxxtopic
*/

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    // 2. 初始化ROS节点；
    ros::init(argc, argv, "info_publisher");
    // 3. 创建节点句柄；
    ros::NodeHandle nh;
    // 4. 创建发布者对象；
    ros::Publisher pub = nh.advertise<std_msgs::String>("house", 10);
    // 5. 编写发布逻辑并发布数据, 要求以10HZ的频率发布数据, 并且文本后添加编号
    // 5.1 先创建被发布的消息
    std_msgs::String msg;
    // 5.2 发布频率--->10HZ
    ros::Rate rate(10);
    // 5.3 设置编号
    int count = 0;
    ros::Duration(3).sleep(); // 持续休息3秒再发布，避免出现发布信息早于发布者注册这一行为的出现，从而造成订阅者订阅的信息出现前面几条丢失
    // 5.3 编写循环，循环发布数据， ros::ok()代表节点只要还活着，则该循环就是成立的
    while(ros::ok()){
        count ++;
        // msg.data = "hello";
        // 实现字符串拼接
        std::stringstream ss;
        ss << "hello ---> " << count;
        msg.data = ss.str(); // 将ss中的数据提取的为字符串
        pub.publish(msg);
        // 添加日志
        ROS_INFO("发布的数据是: %s", ss.str().c_str());
        rate.sleep();
        // ros::spinOnce(); // 官方建议, 处理回调函数，只不过这里发布函数里暂时没用到回调函数，因此这一句可用可不用
    }
    return 0;
}