#include "ros/ros.h"
#include <sstream>
#include "geometry_msgs/Pose.h"

geometry_msgs::Pose pose;

void chatterCallback(const geometry_msgs::Pose::ConstPtr &msg) {
    pose = *msg;
}

void print() {
    ROS_INFO("I heard: [%f],[%f],[%f]",pose.position.x,pose.position.y, pose.orientation.z);
}

int main(int argc, char **argv) {
    ros::init(argc, argv,"sub");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("pose", 100, chatterCallback);

ros::Rate loop_rate(100);
 while (ros::ok()){
    print();
    ros::spinOnce();
    loop_rate.sleep();   
    }

    return 0;
}