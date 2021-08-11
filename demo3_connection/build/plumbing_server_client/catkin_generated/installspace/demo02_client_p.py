#!/usr/bin/env python2
import rospy
# from plumbing_server_client.srv import AddInts, AddIntsRequest, AddIntsResponse
from plumbing_server_client.srv import *
import sys
"""
使用python实现客户端1的消息: 解析服务端请求，处理响应
    1. 导包；
    2. 初始化ros节点;
    3. 创建客户端对象；
    4. 组织请求数据，并发送请求(时间确定，要发送请求的时候就发送请求，所有不需要回调函数)；
    5. 处理响应；

    优化实现1：
        可以在执行节点时动态接收参数
    
    优化实现2：
        问题：客户端先于服务器端启动，会抛出异常
        需求：客户端先于服务端启动，不要抛出异常，而是等待服务器端启动后再发送请求
        实现：ROS内置了函数，可用于在客户端先启动的情况下让其先挂起
"""
if __name__ == "__main__":
    # 判断传入的参数个数，sys.argv第一个参数是文件名，第二个参数数num1，第三个参数是num2
    if len(sys.argv) != 3:
        rospy.logerr("传入的参数个数不对！")
        sys.exit(1)
    # 2. 初始化ros节点;
    rospy.init_node("Client") # 传入节点名称
    # 3. 创建客户端对象；
    client = rospy.ServiceProxy(name="addInts", service_class=AddInts)
    rospy.loginfo("客户端已经启动了.")
    # 4. 组织请求数据，并发送请求
    # 4.1 解析传入的参数
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])
    # 优化客户端先启动的情况1:
    # client.wait_for_service()
    # 优化客户端先启动的情况2:
    rospy.wait_for_service("addInts")
    response = client.call(num1, num2)
    rospy.loginfo("响应的数据：%d", response.sum)
