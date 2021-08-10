#!/usr/bin/env python3
import rospy
import sys 
print(sys.version)
print(sys.version_info)

if __name__ == "__main__":
    rospy.init_node("Hello")
    rospy.loginfo("Hello World!!!!")
    print("python3")