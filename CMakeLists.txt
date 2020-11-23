#Set minimum CMAKE version for this project to ensure compatability
cmake_minimum_required(VERSION 3.1.0)

#Main project
project(
	FileStructurizer
	VERSION 0.0.1
	LANGUAGES CXX)

#Use c++
set(CMAKE_CXX_EXTENSIONS OFF)

#Include folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#Project cofiguration file
#Extracts all key-value pairs from the config file to use in here
#for an easier use of certain settings without modifing the whole CMakeLists.txt
file(STRINGS cmake/cmake.prjconf CONFIG_CONTENT)

foreach(NAME_AND_VALUE ${CONFIG_CONTENT})
	string(REGEX REPLACE "^[ ]+" "" NAME_AND_VALUE ${NAME_AND_VALUE})
	string(REGEX MATCH "^[^=]+" CONF_NAME ${NAME_AND_VALUE})
	string(REPLACE "${CONF_NAME}=" "" CONF_VALUE ${NAME_AND_VALUE})
	set(${CONF_NAME} ${CONF_VALUE})
endforeach()

#Qt5 settings
set(CMAKE_PREFIX_PATH ${Qt5InstallPath})

#Include necessary Qt5 packages
find_package(Qt5 REQUIRED COMPONENTS Widgets)

#Enable all autogen options for Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#Add the main source directory for our target
add_subdirectory(FileStructurizer)