#!/usr/bin/env python2
import rospy
"""
    参数服务器操作之删除_Python实现:
    rospy.delete_param("键")
    键存在时，可以删除成功，键不存在时，会抛出异常
"""


if __name__ == "__main__":
    # 初始化ros
    rospy.init_node("del_params_p")
    
    # 删除参数
    try:
        rospy.delete_param("radius_p")
    except Exception as e:
        rospy.loginfo("被删除的参数不存在")

