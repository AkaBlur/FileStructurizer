#Set minimum CMAKE version for this project to ensure compatability
cmake_minimum_required(VERSION 3.19.0)

#Main project name
project(FileStructurizer)

#CMake compiler standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Project cofiguration file
#Extracts all key-value pairs from the config file to use in here
#for an easier use of certain settings without modifing the whole CMakeLists.txt
file(STRINGS cmake.prjconf CONFIG_CONTENT)

foreach(NAME_AND_VALUE ${CONFIG_CONTENT})
	string(REGEX REPLACE "^[ ]+" "" NAME_AND_VALUE ${NAME_AND_VALUE})
	string(REGEX MATCH "^[^=]+" CONF_NAME ${NAME_AND_VALUE})
	string(REPLACE "${CONF_NAME}" "" CONF_VALUE ${NAME_AND_VALUE})
	set(${CONF_NAME} ${CONF_VALUE})
endforeach()

#Set the main source and resource directory
#Pls don't modify (no need to include in the .prjconf)
set(FS_SOURCE ../${PROJECT_NAME}/src)
set(FS_RES ../${PROJECT_NAME}/res)
#Set the main build directory for CMake
set(FS_BUILD ../build)

#Set the output directory of generated bins
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/${CMAKE_BUILD_TYPE})

#Qt5 settings
set(CMAKE_PREFIX_PATH ${Qt5InstallPath})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (CMAKE_VERSION VERSION_LESS "3.19.0")
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

#Include necessary Qt5 packages
find_package(Qt5 COMPONENTS Widgets REQUIRED)

#The variable automaticaly adds the source directory in the build process
#therefore it has to be omitted here!
#SET ALL HEADERS HERE:
set(${PROJECT_NAME}_HEADERS FileStructurizer.h)
	
list(TRANSFORM ${PROJECT_NAME}_HEADERS PREPEND ${FS_SOURCE}/)

#SET ALL SOURCE FILES HERE:
set(${PROJECT_NAME}_SOURCES main.cpp FileStructurizer.cpp)
	
list(TRANSFORM ${PROJECT_NAME}_SOURCES PREPEND ${FS_SOURCE}/)

#The resource directory is also added later!
#SET ALL RESOURCES HERE:
set(${PROJECT_NAME}_RESOURCES FileStructurizer.qrc)
	
list(TRANSFORM ${PROJECT_NAME}_RESOURCES PREPEND ${FS_RES}/)

#SET ALL UI-FILES HERE:
set(${PROJECT_NAME}_UI FileStructurizer.ui)

list(TRANSFORM ${PROJECT_NAME}_UI PREPEND ${FS_RES}/)
#Create a variable for all headers from the UIC so that the original
#variable for the source files doesn't get modified (for later including it)
set(${PROJECT_NAME}_UI_HEADERS ${${PROJECT_NAME}_UI})
qt5_wrap_ui(${PROJECT_NAME}_UI_HEADERS ${${PROJECT_NAME}_UI})
#Include the resource directory for the UIC to search for the *.ui files
set(CMAKE_AUTOUIC_SEARCH_PATHS ${FS_RES})

#Generate the executable
add_executable(FileStructurizer
	#Resource related files
	${${PROJECT_NAME}_RESOURCES}
	#UI files
	${${PROJECT_NAME}_UI_HEADERS}
	#Source code
	${${PROJECT_NAME}_HEADERS}
	${${PROJECT_NAME}_SOURCES}
)

#Include source and resource directories for the compiler
target_include_directories(${PROJECT_NAME} PRIVATE /)
target_include_directories(${PROJECT_NAME} PRIVATE ${FS_SOURCE})
target_include_directories(${PROJECT_NAME} PRIVATE ${FS_RES})
target_include_directories(${PROJECT_NAME} PRIVATE ${FS_BUILD})

#Link the necessary libs
target_link_libraries(FileStructurizer Qt::Widgets)