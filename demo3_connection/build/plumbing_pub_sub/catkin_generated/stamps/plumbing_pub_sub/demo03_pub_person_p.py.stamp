#! /usr/bin/env python
import rospy
from plumbing_pub_sub.msg import Person
"""
使用python实现发布人的消息:
    1. 导包；
    2. 初始化ros节点;
    3. 创建发布者对象；
    4. 编写发布逻辑并发布数据；
"""
if __name__ == "__main__":
    # 2. 初始化ros节点;
    rospy.init_node("Teacher") # 传入节点名称
    # 3. 创建发布者对象；
    pub = rospy.Publisher(name="Teacher_Info", data_class=Person, queue_size=10)
    # 4. 编写发布逻辑并发布数据；
    # 4.1 创建数据
    Teacher = Person()
    Teacher.name = "班主任"
    Teacher.age = 30
    Teacher.height = 1.8
    # 4.2 指定发布频率
    rate = rospy.Rate(hz=1)
    # 4.3 循环实现发布数据
    rospy.sleep(3)
    while not rospy.is_shutdown():
        # 4.4 发布数据
        pub.publish(Teacher)
        rospy.loginfo("发布的数据是：%s, %d, %.2f", Teacher.name, Teacher.age, Teacher.height)
        rate.sleep()
