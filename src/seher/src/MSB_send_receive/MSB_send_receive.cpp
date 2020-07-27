#include <ros/ros.h>
#include "std_msgs/Float32.h"
#include "rosgraph_msgs/Clock.h"
#include <fstream>

ros::Duration delay;
ros::Time t_send;
ros::Time t_receive;

using namespace std;
ofstream outfile;
int i=0;

ros::Publisher distance_send;

void distanceCallback (const std_msgs::Float32::ConstPtr& dst){
    //std_msgs::Float32 dist;
    //dist.data=dst->data;
    rosgraph_msgs::Clock time_send;
    time_send.clock=ros::Time::now();
    distance_send.publish(time_send);

}

void distanceReceiveCallback (const rosgraph_msgs::Clock::ConstPtr& t){
    t_receive=ros::Time::now();
    delay=t_receive-t->clock;
    outfile << i << " : " << delay << endl;
    i++;


}


int main(int argc, char** argv){
  ros::init(argc, argv, "MSB_send_receive");

  ros::NodeHandle node;


  ros::Subscriber distance_sub = node.subscribe("/distance_calculation/minimal_distance",1, distanceCallback);
  distance_send=node.advertise<rosgraph_msgs::Clock>("/distance_calculation/minimal_distance/send",1);
  ros::Subscriber distance_get = node.subscribe("/distance_calculation/minimal_distance/receive",1, distanceReceiveCallback);

   
  
  outfile.open("MSB_send_receive.dat");
  
  while (node.ok()){
      ros::spinOnce();
  }
    

  outfile.close();
  
  return 0;
};