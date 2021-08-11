#! /usr/bin/env python
import rospy
"""
    演示参数的新增与修改
    需求：在参数服务器中设置机器人属性，型号和半径；
    实现:
        rospy.set_param()
"""


if __name__ == "__main__":
    # 初始化ros
    rospy.init_node("set_params_p");
    # 新增参数
    rospy.set_param(param_name="type_p", param_value="Hellodanche")
    rospy.set_param(param_name="radius_p", param_value=0.1)
    # 修改参数
    rospy.set_param(param_name="radius_p", param_value=0.9)