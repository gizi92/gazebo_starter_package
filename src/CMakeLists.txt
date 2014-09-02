cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_library(create_joint SHARED create_joint.cc)
target_link_libraries(create_joint ${GAZEBO_libraries} ${OGRE_LIBRARIES})

add_library(system_subscriber SHARED system_subscriber.cpp)
target_link_libraries(system_subscriber ${GAZEBO_LIBRARIES} ${OGRE_LIBRARIES} ${Boost_LIBRARIES} ${PROTOBUF_LIBRARIES})

add_library(system_publisher SHARED system_publisher.cpp)
target_link_libraries(system_publisher ${GAZEBO_LIBRARIES} ${Boost_LIBRARIES} ${PROTOBUF_LIBRARIES})

add_library(get_phys_engine SHARED get_phys_engine.cpp)
target_link_libraries(get_phys_engine ${GAZEBO_LIBRARIES})
