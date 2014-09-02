#include "get_phys_engine.hh"

using namespace gazebo;

void GetPhysEngine::Load(physics::WorldPtr _parent, sdf::ElementPtr /*_sdf*/)
{
	this->world = _parent;
	this->engine = this->world->GetPhysicsEngine();
	std::cout << "World name : " << this->world->GetName() << std::endl;
//	std::cout << "Physics engine type : " << this->engine->GetType() << std::endl;
}

GZ_REGISTER_WORLD_PLUGIN(GetPhysEngine)
