#! /usr/bin/env python
import rospy
from plumbing_pub_sub.msg import Person
"""
使用python实现消息订阅方:
    1. 导包；
    2. 初始化ros节点;
    3. 创建订阅者对象；
    4. 回调函数处理数据；
    5. spin()处理回调函数；
"""
def handleMsg(msg):
    rospy.loginfo("subscriber get info: %s, %d, %.2f", msg.name, msg.age, msg.height)


if __name__ == "__main__":
    # 2. 初始化ros节点;
    rospy.init_node("Parent") # 传入节点名称
    # 3. 创建订阅者对象；
    sub = rospy.Subscriber(name="Teacher_Info", data_class=Person, queue_size=10, callback=handleMsg)
    # 4. 回调函数处理数据；
    # 5. spin()
    rospy.spin()