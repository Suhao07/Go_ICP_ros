cmake_minimum_required(VERSION 3.0.2)

project(pcd_publisher)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  pcl_ros
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(pcd_publisher_node src/pc_publisher.cpp)

target_link_libraries(pcd_publisher_node
  ${catkin_LIBRARIES}
)


