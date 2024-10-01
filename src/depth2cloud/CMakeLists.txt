cmake_minimum_required(VERSION 3.0.2)
project(depth2cloud)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  cv_bridge
  pcl_ros
  image_transport
)

find_package(OpenCV REQUIRED)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(depth2cloud_node src/depth2cloud_node.cpp)

target_link_libraries(depth2cloud_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)