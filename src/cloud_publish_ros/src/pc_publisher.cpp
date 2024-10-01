#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl_ros/point_cloud.h>

int main(int argc, char** argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "pcd_publisher");
    ros::NodeHandle nh;

    // 创建发布者
    ros::Publisher pub_object_ = nh.advertise<sensor_msgs::PointCloud2>("online_object_detector/object_cloud", 1);
    ros::Publisher pub_camera_ = nh.advertise<sensor_msgs::PointCloud2>("online_object_detector/camera_cloud", 1);




    // 加载PCD文件
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    if (pcl::io::loadPCDFile<pcl::PointXYZRGB>("/home/cv/Desktop/GO_ICP/src/cloud_publish_ros/data/source.pcd", *cloud) == -1)
    {
        PCL_ERROR("Couldn't read file source.pcd \n");
        return (-1);
    }

    // 设置发布频率
    ros::Rate loop_rate(1); // 1 Hz




    while (ros::ok())
    {
        // 将PCL点云转换为ROS消息
        sensor_msgs::PointCloud2 output;
        pcl::toROSMsg(*cloud, output);
        output.header.frame_id = "map";

        // 发布点云消息
        pub_object_.publish(output);

        ros::spinOnce();
        loop_rate.sleep();
        PCL_INFO("Publishing a point cloud message\n");
    }

    return 0;
}

// "/online_object_detector/camera_cloud"
// "/online_object_detector/object_cloud"