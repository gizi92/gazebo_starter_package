#include "system_subscriber.hh"

using namespace gazebo;

//////////////////////////////////////////////////
void SystemSubscriber::Load(int /*_argc*/, char ** /*_argv*/)
{
	this->sceneNode = NULL;
	this->entity = NULL;
}

void SystemSubscriber::Init()
{
	this->updateConnection = event::Events::ConnectPreRender(
			boost::bind(&SystemSubscriber::CreateSphere, this));
}

//////////////////////////////////////////////////
void SystemSubscriber::CreateSphere()
{
	this->manager = gui::get_active_camera()->GetScene()->GetManager();
	this->sceneNode = this->manager->getRootSceneNode()->createChildSceneNode(
			"MySphere");
	this->entity = this->manager->createEntity("MySphere",
			Ogre::SceneManager::PT_SPHERE);
	this->entity->setMaterialName("Gazebo/Red");
	this->sceneNode->setVisible(true);
	this->entity->setVisible(true);
	this->sceneNode->setScale(0.001, 0.001, 0.001);
	this->sceneNode->setPosition(0, 1, 1);
	this->sceneNode->attachObject(entity);
	this->CreateSubscriber();
	this->updateConnection.reset();
}

//////////////////////////////////////////////////
void SystemSubscriber::CreateSubscriber()
{
	this->node = transport::NodePtr(new transport::Node());
	this->node->Init("EmptyWorld");
	this->sub = node->Subscribe("/gazebo/EmptyWorld/sphere_topic",
			&SystemSubscriber::callback, this);
	std::cout << "Subscribing to topic : ~/sphere_topic" << std::endl;
}

//////////////////////////////////////////////////
void SystemSubscriber::callback(
		const boost::shared_ptr<const gazebo::msgs::Vector3d> &_msg)
{
	std::cout << _msg->DebugString() << std::endl;
	this->sceneNode->setPosition(_msg->x(), _msg->y(), _msg->z());
}

GZ_REGISTER_SYSTEM_PLUGIN(SystemSubscriber)
