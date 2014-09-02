#ifndef _GET_PHYS_ENGINE_HH
#define _GET_PHYS_ENGINE_HH

#include "gazebo/gazebo.hh"
#include "gazebo/physics/physics.hh"

namespace gazebo
{
	class GetPhysEngine: public WorldPlugin
	{
	public:
		void Load(physics::WorldPtr _parent, sdf::ElementPtr /*_sdf*/);

		physics::PhysicsEnginePtr engine;

		physics::WorldPtr world;
	};
}
#endif
