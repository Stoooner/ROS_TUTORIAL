#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
/*
    服务端实现：解析客户端提交的数据，并运算再产生响应
    1. 包含头文件；
    2. 初始化ros节点；
    3. 创建节点句柄；
    4. 创建服务对象；
    5. 处理请求并产生相应；
    6. spin()
*/

bool addNums(plumbing_server_client::AddInts::Request &request, 
             plumbing_server_client::AddInts::Response &response){
    // 1. 处理请求
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("收到的请求数据为: num1=%d, num2=%d", num1, num2);
    // 2. 组织响应
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("求和的结果为: sum=%d", sum);
    return true;
}

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    // 2. 初始化ros节点(节点是执行计算的进程)；
    ros::init(argc, argv, "Server");
    // 3. 创建节点句柄；
    ros::NodeHandle nh;
    // 4. 创建服务对象(nh.advertise是创建一个发布者对象，nh.advertiseService是创建一个Service对象, addNums是一个回调函数)；
    ros::ServiceServer server = nh.advertiseService("addInts", addNums);
    ROS_INFO("服务器端已启动!");
    // 5. 处理请求并产生相应；
    // 6. spin()；
    ros::spin();
    return 0;
}