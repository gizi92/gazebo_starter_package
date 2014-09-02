cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)
FIND_PACKAGE( Boost 1.40 COMPONENTS system REQUIRED )
set (CMAKE_CXX_FLAGS "-g -Wall")

include (FindPkgConfig)
if (PKG_CONFIG_FOUND)
  find_package(gazebo REQUIRED)
  pkg_check_modules(SDF sdformat)
  pkg_check_modules(OGRE OGRE)
  pkg_check_modules(OGRE-Terrain OGRE-Terrain)

endif()   

include(FindBoost)
find_package(Boost ${MIN_BOOST_VERSION} REQUIRED system filesystem regex)
find_package(Protobuf REQUIRED)
message(${GAZEBO_INCLUDE_DIRS})

include_directories(
	include
	${GAZEBO_INCLUDE_DIRS}
    	${OGRE_INCLUDE_DIRS}
	${OGRE-Terrain_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/include
)

link_directories(
	${GAZEBO_LIBRARY_DIRS} 
	${OGRE_LIBRARY_DIRS}
	${SDF_LIBRARY_DIRS}
	
)

add_subdirectory(src)


