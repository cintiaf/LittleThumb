//
// Created by julien on 12/13/15.
//

#include <iostream>
#include "ros/ros.h"
#include "beginner_tutorials/javaClient.h"

bool fromServer(beginner_tutorials::javaClient::Request  &req,
                beginner_tutorials::javaClient::Response &res)
{
    std::cout << "action:" << req.action <<  std::endl <<
            "engineFL" << req.engineFL <<std::endl <<
            "engineFR" << req.engineFR <<std::endl <<
            "engineBL" << req.engineBL <<std::endl <<
            "engineBR" << req.engineBR <<std::endl <<
            "speed" << req.time << std::endl << std::endl;
    res.ret = 14;
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "javaLittleThumb");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("javaClient", &fromServer);
    ros::spin();
}