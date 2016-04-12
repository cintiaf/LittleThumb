//
// Created by julien on 12/13/15.
//

#include "ServerROS.h"

ServerROS::ServerROS()
{
}

void ServerROS::run(int argc, char **argv)
{
    ros::init(argc, argv, "littleThumb");
    ros::NodeHandle n;
    _clientJava = n.serviceClient<beginner_tutorials::javaClient>("javaClient");

    std::cout << "server running" << std::endl;
    ros::ServiceServer service = n.advertiseService("graphicClient", &ServerROS::displayMsg, this);
    ros::spin();
}

bool ServerROS::displayMsg(beginner_tutorials::graphicClient::Request  &req,
                           beginner_tutorials::graphicClient::Response &res)
{
    std::cout << "displayMsg" << std::endl;
    _srv.request.action =  req.action;
    _srv.request.engineFL =  req.engineFL;
    _srv.request.engineFR =  req.engineFR;
    _srv.request.engineBL =  req.engineBL;
    _srv.request.engineBR =  req.engineBR;
    _srv.request.time =  req.time;

    if (_clientJava.call(_srv))
    {
        res.ret = _srv.response.ret;
        ROS_INFO("Sum: %ld", (long int)_srv.response.ret);
    }
    else
    {
        ROS_ERROR("Failed to call service javaClient");
        return 1;
    }

    return (true);
}