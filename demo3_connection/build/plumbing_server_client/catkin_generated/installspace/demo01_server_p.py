#!/usr/bin/env python2
import rospy
# from plumbing_server_client.srv import AddInts, AddIntsRequest, AddIntsResponse
from plumbing_server_client.srv import *
"""
使用python实现服务器端的消息: 解析服务端请求，产生响应
    1. 导包；
    2. 初始化ros节点;
    3. 创建服务器端对象；
    4. 处理请求产生响应(回调函数--->因为处理请求的时间是不确定的，得等到客户端发请求才能处理请求)；
    5. spin()函数
"""
# 参数：封装的请求数据， 返回值：相应数据
def addNums(request):
    # 1. 解析提交的两个整数
    num1 = request.num1
    num2 = request.num2
    # 2. 求和
    sums = num1 + num2
    # 3. 将结果封装进响应对象
    response = AddIntsResponse()
    response.sum = sums
    rospy.loginfo("服务器解析的数据: num1=%d, num2=%d, 响应的结果: sum=%d", num1, num2, sums)
    return response

if __name__ == "__main__":
    # 2. 初始化ros节点;
    rospy.init_node("Server") # 传入节点名称
    # 3. 创建服务器端对象；
    server = rospy.Service(name="addInts", service_class=AddInts, handler=addNums)
    rospy.loginfo("服务器端已经启动了！")
    # 4. 处理请求产生响应；
    # 5. spin()函数
    rospy.spin()