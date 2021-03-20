#!/usr/bin/env python
# coding:utf-8

import rospy
from yolo_rect.msg import Boxes, One_box

if __name__ == '__main__':
    nodeName = "topic_py_publisher5"
    rospy.init_node(nodeName)

    # 创建发布者
    topicName = "rect_topic"
    publisher = rospy.Publisher(topicName, Boxes, queue_size=1000)

    rate = rospy.Rate(1)
    index = 0
    while not rospy.is_shutdown():
        a=One_box()
        a.x1=1+index
        a.x2=2+index
        a.y1=3+index
        a.y2=4+index

        b=Boxes()
        b.boxes.append(a)
        b.boxes.append(a)
        b.boxes.append(a)

        publisher.publish(b)

        rate.sleep()
        index += 1

    rospy.spin()
