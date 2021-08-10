#!/usr/bin/env python3
import rospy
import sys 
print(sys.version)
print(sys.version_info)

if __name__ == "__main__":
    rospy.init_node("ros_python")
    rospy.loginfo("hevscode, 这是python版本")
    print("python3")