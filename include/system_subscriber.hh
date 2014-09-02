#ifndef _SYSTEM_SUBSCRIBER_HH
#define _SYSTEM_SUBSCRIBER_HH

#include "gazebo/gui/GuiIface.hh"
#include "gazebo/transport/transport.hh"
#include "gazebo/msgs/msgs.hh"
#include "gazebo/rendering/rendering.hh"
#include "gazebo/gazebo.hh"

namespace gazebo{

 	 /// \Class SystemSubscriber system_subscriber.hh
 	 /// \brief Class for creating a sphere with Ogre and subscribing to a topic
 	 class SystemSubscriber: public SystemPlugin
 	 {
 		 /// \brief Standard Ogre scene node.
 		 public: Ogre::SceneNode *sceneNode;

 		 /// \brief Standard Ogre entity.
 		 public: Ogre::Entity *entity;

 		 /// \brief Srandard Ogre scene manager.
 		 public: Ogre::SceneManager *manager;

 		 /// \brief Transport node pointer.
 		 public: gazebo::transport::NodePtr node;

 		 /// \brief Subscriber pointer.
 		 public: gazebo::transport::SubscriberPtr sub;

 		 /// \brief Standard connection pointer.
 		 public: event::ConnectionPtr updateConnection;

 		 /// \brief Load
 		 public: void Load(int /*_argc*/, char ** /*_argv*/);

 		 /// \brief Standard Init
 		 public: virtual void Init();

 		 /// \brief Creates a sphere using the rendering engine
 		 public: void CreateSphere();

 		 /// \brief Creates the transport node and subscribes to the topic ~/sphere_topic
 		 public: void CreateSubscriber();

 		 /// \brief Callback function to handle the messages coming from the topic
 		 public: virtual void callback(const boost::shared_ptr<const gazebo::msgs::Vector3d> &_msg);
 };
}
#endif
