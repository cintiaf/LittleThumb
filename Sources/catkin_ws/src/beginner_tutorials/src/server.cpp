
#include "ServerROS.h"

int main(int argc, char **argv)
{
  /*
  ros::init(argc, argv, "moveCommand");
  ros::NodeHandle n;
*/
  ServerROS serv;
  serv.run(argc, argv);
/*  ros::ServiceServer service = n.advertiseService("graphicClient", &ServerROS::displayMsg, &serv);
  ros::spin();*/

  return 0;
}
