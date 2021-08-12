#!/usr/bin/env python2
import rospy
from turtlesim.srv import Spawn,SpawnRequest,SpawnResponse
# import sys 
# print(sys.version)
# print(sys.version_info)
"""
    需求：向服务器发送请求，用于生成一只小乌龟
    话题：/spawn
    消息：turtlesim/Spawn
    
    实现流程:
        1.导包
        2.初始化ROS节点
        3.创建客户端对象
        4.组织数据并发送请求
        5.处理响应结果
"""
if __name__ == "__main__":
    # 2.初始化ROS节点
    rospy.init_node("turtle_spawn_client")
    # 3.创建客户端对象
    client = rospy.ServiceProxy(name="/spawn", service_class=Spawn)
    # 4.使用回调函数处理订阅到的消息
    # 4.1 组织数据
    request = SpawnRequest()
    request.x = 4.5
    request.y = 2.0
    request.theta = -3
    request.name = "turtle3"
    # 4.2 判断服务器状态并发送
    client.wait_for_service()
    try:
        response = client.call(request)
        # 5.处理响应结果
        rospy.loginfo("生成的乌龟的名字叫: %s", response.name)
    except Exception as e:
        rospy.logerr("请求处理异常！")