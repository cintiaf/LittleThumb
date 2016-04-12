//
// Created by julien on 12/13/15.
//

#ifndef SRC_SERVERROS_HH_H
#define SRC_SERVERROS_HH_H

#include <iostream>
#include "ros/ros.h"
#include "beginner_tutorials/graphicClient.h"
#include "beginner_tutorials/javaClient.h"

class ServerROS
{
public:
    ServerROS();
    bool displayMsg(beginner_tutorials::graphicClient::Request  &req,
                    beginner_tutorials::graphicClient::Response &res);
    void run(int argc, char **argv);
private:
    ros::ServiceClient _clientJava;
    beginner_tutorials::javaClient _srv;
};

#endif //SRC_SERVERROS_HH_H
