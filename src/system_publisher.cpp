#include "system_publisher.hh"

using namespace gazebo;

//////////////////////////////////////////////////
void SystemPublisher::Load(int /*_argc*/, char ** /*_argv*/)
{
	this->counter = 0;
	this->updateRate = common::Time(2, 0);
	this->prevUpdateTime = common::Time::GetWallTime();
}

//////////////////////////////////////////////////
void SystemPublisher::Init()
{
	this->node = transport::NodePtr(new transport::Node());
	this->node->Init("EmptyWorld");
	this->pub = node->Advertise<gazebo::msgs::Vector3d>("~/sphere_topic");
	this->loadConnection = event::Events::ConnectWorldUpdateBegin(
			boost::bind(&SystemPublisher::OnUpdate, this));
}

//////////////////////////////////////////////////
void SystemPublisher::OnUpdate()
{
	if (common::Time::GetWallTime() - this->prevUpdateTime < this->updateRate)
		return;

	this->vector = gazebo::math::Vector3(this->counter, 1, 1);
	gazebo::msgs::Set(&msg, vector);
	pub->Publish(msg);
	this->counter = counter + 0.1;

	this->prevUpdateTime = common::Time::GetWallTime();
}

GZ_REGISTER_SYSTEM_PLUGIN(SystemPublisher)
