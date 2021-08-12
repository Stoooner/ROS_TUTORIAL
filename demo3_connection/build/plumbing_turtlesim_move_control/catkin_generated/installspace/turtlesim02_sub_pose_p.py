#!/usr/bin/env python2
import rospy
from turtlesim.msg import Pose
# import sys 
# print(sys.version)
# print(sys.version_info)
"""
    需求：编写ROS节点用于订阅并输出乌龟位姿信息

    实现流程:
        1.导包
        2.初始化ROS节点
        3.创建订阅对象
        4.使用回调函数处理订阅到的消息
        5.spin()
    注意：
        坐标点是相对于坐标系而言的，在乌龟GUI中坐标系中心点是在图像左下角的，横向是x轴，纵向是y轴
"""

def handlePose(pose_info):
    rospy.loginfo("乌龟的位姿信息: 坐标(x=%.2f, y=%.2f), 朝向(%.2f), 线速度:%.2f, 角速度: %.2f",
              pose_info.x, pose_info.y, pose_info.theta, 
              pose_info.linear_velocity,
              pose_info.angular_velocity)

if __name__ == "__main__":
    # 2.初始化ROS节点
    rospy.init_node("turtle_pose_subscriber")
    # 3.创建发布者对象
    sub = rospy.Subscriber(name="/turtle1/pose", data_class=Pose, callback=handlePose, queue_size=100)
    # 4.使用回调函数处理订阅到的消息
    # 5.spin()
    rospy.spin()