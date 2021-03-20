# 1 自定义消息（数组）
```
<build_depend>message_generation</build_depend>
<exec_depend>message_runtime</exec_depend>

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  actionlib
  actionlib_msgs
  message_generation
)

 add_message_files(
   FILES
   One_box.msg
   Boxes.msg
 )
 
  generate_messages(
   DEPENDENCIES
   actionlib_msgs
   std_msgs
 )
 
 
 catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES yolo_rect
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
#  DEPENDS system_lib
)
 
```
