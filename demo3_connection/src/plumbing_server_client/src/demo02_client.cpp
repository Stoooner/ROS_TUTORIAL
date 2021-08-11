#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
/*
    客户端实现：提交两个整数，处理响应了的结果
    1. 包含头文件；
    2. 初始化ros节点；
    3. 创建节点句柄；
    4. 创建客户端对象；
    5. 提交请求处理响应；

    实现参数的动态提交:
        1. 格式：rosrun xxxx xxxx num1 num2
        2. 节点执行时，需要获取命令参数，并组织进request；
    
    问题：
        如果先启动客户端会出现请求异常；
    需求：
        如果先启动客户端，不要直接抛出异常，而是直接挂起，等待服务器端启动后再处理请求
    解决：
        在ROS中已经内置了相关函数，这些函数可以让客户端启动后挂起，等待服务器启动
        1. client.waitForExistence();
        2. ros::service::waitForService("服务的话题名");
*/

/**
 * argc是argument count的缩写，表示传入main函数的参数个数；
 * argv是argument vector的缩写，表示传入main函数的参数序列或指针，并且第一个参数argv[0]一定是程序的名称，
 * 并且包含了程序所在的完整路径，所以确切的说需要我们输入的main函数的参数个数应该是argc-1个；
 * 所以rosrun xxxx xxxx是第一个参数，num1 num2是第2个和第3个参数，因此argc=3，所有num1=atoi(argv[1])， num2=atoi(argv[2]) 
*/
int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    // 优化实现，获取命令行中的参数
    if (argc != 3){
        ROS_INFO("提交的参数个数不对!");
        return 1;
    }
    // 2. 初始化ros节点(节点是执行计算的进程)；
    ros::init(argc, argv, "Client");
    // 3. 创建节点句柄；
    ros::NodeHandle nh;
    // 4. 创建服务对象(nh.advertise是创建一个发布者对象，nh.advertiseService是创建一个Service对象, addNums是一个回调函数)；
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    ROS_INFO("客户端已启动!");
    // 5. 处理请求并产生相应；
    plumbing_server_client::AddInts AI;
    // 5.1 组织请求
    AI.request.num1 = atoi(argv[1]);
    AI.request.num2 = atoi(argv[2]);
    // 5.2 处理响应
    // 5.3 调用判断服务器状态的函数
    // 函数1: 调用之后，如果服务器端没有启动，则客户端被挂起，等待服务器端启动
    // client.waitForExistence();
    // 函数2：这个函数需要传参，传入的是被等待的这个服务名，这里就是"addInts"
    ros::service::waitForService("addInts");
    bool flag = client.call(AI);
    if (flag){
        // 获取结果
        ROS_INFO("响应成功! 结果为：%d", AI.response.sum);
    }
    else{
        ROS_INFO("处理失败！");
    }
    return 0;
}