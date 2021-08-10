#! /usr/bin/env python
import rospy
from std_msgs.msg import String # 导入需要发布消息的数据类型的包

"""
使用python实现消息发布方:
    1. 导包；
    2. 初始化ros节点;
    3. 创建发布者对象；
    4. 编写发布逻辑并发布数据；
"""


if __name__ == "__main__":
    # 2. 初始化ros节点;
    rospy.init_node("info_publisher") # 传入节点名称
    # 3. 创建发布者对象；
    pub = rospy.Publisher(name="Car", data_class=String, queue_size=10)
    # 4. 编写发布逻辑并发布数据；
    # 4.1 创建数据
    msg = String()
    # 4.2 指定发布频率
    rate = rospy.Rate(hz=1)
    # 设置计数器
    count = 0
    # 4.3 循环实现发布数据
    rospy.sleep(3)
    while not rospy.is_shutdown():
        count += 1
        msg.data = "hello" + str(count)
        # 4.4 发布数据
        pub.publish(msg)
        rospy.loginfo("发布的数据是：%s", msg.data)
        rate.sleep()
