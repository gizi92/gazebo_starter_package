#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
//#include <create_joint.hh>

//using namespace Homework2;

namespace gazebo {
class Homework2: public WorldPlugin {
public:
	physics::WorldPtr world;
public:
	physics::ModelPtr object1;
public:
	physics::ModelPtr object2;
public:
	event::ConnectionPtr loadWorld;
public:
	physics::JointPtr myJoint;
public:
	physics::PhysicsEnginePtr engine;
public:
	math::Pose jointPose;
public:
	common::Time prevWallTime;
public:
	bool flagMin;
public:
	bool flagMax;

public:
	void Load(physics::WorldPtr _parent, sdf::ElementPtr /*_sdf*/) {
		world = _parent;
		std::cout << world->GetName() << std::endl;
		object1 = world->GetModel("object_1");
		object2 = world->GetModel("object_2");
		engine = world->GetPhysicsEngine();
		this->prevWallTime = common::Time::GetWallTime();
		this->flagMin = false;
		this->flagMax = false;
	}
public:
	void Init() {
		this->loadWorld = event::Events::ConnectWorldUpdateBegin(
				boost::bind(&Homework2::OnUpdate, this));
	}
public:
	void OnUpdate() {
		object2->SetLinearVel(math::Vector3(0, 0, 0.5));
		if ((common::Time::GetWallTime().sec - this->prevWallTime.sec) > 5
				&& !flagMin)
		{
			std::cout << "TIME DIFF LARGER THAN 4 SEC" << std::endl;

			this->myJoint = this->engine->CreateJoint("revolute",
					this->object1);
			this->jointPose = math::Pose(1, 1, 0, 0, 1, 0);
			myJoint->Load(this->object1->GetLink("ob_1_link"),
					this->object2->GetLink("ob_2_link"), this->jointPose);
			myJoint->Attach(this->object1->GetLink("ob_1_link"),
					this->object2->GetLink("ob_2_link"));
			std::cout << "Joint attached successfully!" << std::endl;
			object2->SetLinearVel(math::Vector3(0, 0, 0.5));
			this->flagMin = true;
		}

		if ((common::Time::GetWallTime().sec - this->prevWallTime.sec) > 15
				&& !flagMax) {
			std::cout << "TIME DIFF LARGER THAN 12 SEC" << std::endl;
			myJoint->Detach();
			std::cout << "Joint detached!";
			this->flagMax = true;
		}

	}

};
GZ_REGISTER_WORLD_PLUGIN (Homework2)
}
