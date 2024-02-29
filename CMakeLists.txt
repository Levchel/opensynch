# CMakeList.txt: проект CMake для Planar Systemus; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
#project(OpenSynch)
cmake_minimum_required (VERSION 3.14)
project(OpenSynchOld)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#####find_library(eigen-3.-4.0/Eigen)
#find_package(Eigen-3.4.0/eig  REQUIRED NO_MODULE)




INCLUDE_DIRECTORIES ("C:/Program Files/Eigen3")
#find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

# Define of the OpenPH:
include_directories(OpenPH/math/algebra/include)
include_directories(OpenPH/math/mathlist/include)
include_directories(OpenPH/phys/physlist/include)
add_subdirectory(OpenPH/math/algebra)
add_subdirectory(OpenPH/math/mathlist)
add_subdirectory(OpenPH/phys/physlist)


# Define of this library (Module-Math):
include_directories(Module-Math/graph/include)
include_directories(Module-Math/fdm/include)
include_directories(Module-Math/time/include)
add_subdirectory(Module-Math/graph)
add_subdirectory(Module-Math/fdm)
add_subdirectory(Module-Math/time)


# Define of this library (Module-MAC):
include_directories(Module-MAC/agent/include)
include_directories(Module-MAC/network/include)
include_directories(Module-MAC/protocol/include)
include_directories(Module-MAC/mas/include)
#include_directories(Module-MAC/manager/include)
add_subdirectory(Module-MAC/agent)
add_subdirectory(Module-MAC/network)
add_subdirectory(Module-MAC/protocol)
add_subdirectory(Module-MAC/mas)
#add_subdirectory(Module-MAC/manager)

#define of this library(EIGen)
#target_link_directories(main Eigen3::Eigen)

# Define of the motion:

add_executable(OpenSynchOld main.cpp)

target_link_libraries(OpenSynchOld      physlist
                                mathlist
                                graph
                                time
                                fdm
                                agent
                                network
                                protocol
                                manager
                                mas
                                objects
                                equations
                                models
                                tactic
                                actuator
                                ${SOURCE_LIB})
 #add_executable(OpenSynch-2 main.cpp)

