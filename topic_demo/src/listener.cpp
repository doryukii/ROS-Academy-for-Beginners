//ROS头文件
#include <ros/ros.h>
//包含自定义msg产生的头文件
#include <topic_demo/gps.h>
//ROS标准msg头文件
#include <std_msgs/Float32.h>

void gpsCallback(const topic_demo::gps::ConstPtr &msg)
{  
    //计算离原点(0,0)的距离
    std_msgs::Float32 distance;
    distance.data = sqrt(pow(msg->x,2)+pow(msg->y,2));
    //float distance = sqrt(pow(msg->x,2)+pow(msg->y,2));
    ROS_INFO("Listener: Distance to origin = %f, state: %s",distance.data,msg->state.c_str());
}

int main(int argc, char **argv)
{
    //ROS节点初始化
  ros::init(argc, argv, "listener");
    //创建节点句柄
  ros::NodeHandle n;
    //创建一个Subscriber，订阅名为gps_info的topic，注册回调函数gspCallback
    //其中参数1为消息队列的缓冲区长度，若要尽量实收实发，队列长度越小越好
  ros::Subscriber sub = n.subscribe("gps_info", 1, gpsCallback);
  //ros::spin()用于调用所有可触发的回调函数。将进入循环，不会返回，类似于在循环里反复调用ros::spinOnce()。
  ros::spin(); 
  return 0;
}

