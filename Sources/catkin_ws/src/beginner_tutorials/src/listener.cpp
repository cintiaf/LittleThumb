#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  beginner_tutorials::Num srv;

  srv.num = 5;
  srv.num2 = 10;

  //  ros::Publisher chatter_pub = n.advertise<beginner_tutorials::Num>(3, 1000);
  ros::spin();

  return 0;
}
