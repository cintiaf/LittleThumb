#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>
#include "beginner_tutorials/Num.h"
#include "beginner_tutorials/graphicClient.h"
#include "beginner_tutorials/javaClient.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::graphicClient>("graphicClient");
  beginner_tutorials::graphicClient srv2;

  srv2.request.dir1 = "a";
  srv2.request.dir2 = "A"; 
  srv2.request.speed = 15;
  std::cout << "dasdas" << std::endl;
  for (int i=0; i<10; ++i)
  {
    if (client.call(srv2))
    {
      ROS_INFO("Sum: %ld", (long int)srv2.response.ret);
    }
    else
    {
      ROS_ERROR("Failed to call service add_two_ints");
      return 1;
    }
  }

  return 0;
}
