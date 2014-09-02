#ifndef _SYSTEM_PUBLISHER_HH
#define _SYSTEM_PUBLISHER_HH

#include "gazebo/gazebo.hh"
#include "gazebo/transport/TransportIface.hh"
#include "gazebo/msgs/msgs.hh"

namespace gazebo {

	/// \Class SystemPublisher system_publisher.hh
	/// \brief Class for publishing vector3d messages
	class SystemPublisher: public SystemPlugin
	{
		/// \brief Standard connection pointer.
		public: event::ConnectionPtr loadConnection;

		/// \brief Transport node pointer.
		public: gazebo::transport::NodePtr node;

		/// \brief Transport publisher pointer.
		gazebo::transport::PublisherPtr pub;

		/// \brief Math vector.
		gazebo::math::Vector3 vector;

		/// \brief Standard double vector message.
		gazebo::msgs::vector3d msg;

		/// \brief Time variable for throttling the update rate.
		common::Time updateRate;

		/// \brief Time variable for saving wall time value.
		common::Time prevUpdateTime;

		/// \brief Integer variable.
		double counter;

		/// \brief Standard Load.
		virtual void Load(int /*_argc*/, char ** /*_argv*/);

		/// \brief Standard Init.
		virtual void Init();

		/// \brief Update function for publishing messages on a topic.
		virtual void OnUpdate();
	};
}

#endif
