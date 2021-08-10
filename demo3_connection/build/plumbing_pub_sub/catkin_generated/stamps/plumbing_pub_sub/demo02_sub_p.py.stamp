#! /usr/bin/env python
import rospy
from std_msgs.msg import String # 导入需要发布消息的数据类型的包

"""
使用python实现消息订阅方:
    1. 导包；
    2. 初始化ros节点;
    3. 创建订阅者对象；
    4. 回调函数处理数据；
    5. spin()处理回调函数；
"""
def handleMsg(msg):
    rospy.loginfo("subscriber get info: %s", msg.data)


if __name__ == "__main__":
    # 2. 初始化ros节点;
    rospy.init_node("info_subscriber") # 传入节点名称
    # 3. 创建订阅者对象；
    sub = rospy.Subscriber(name="house", data_class=String, queue_size=10, callback=handleMsg)
    # 4. 回调函数处理数据；
    # 5. spin()
    rospy.spin()