#Set the search path for the AUTOUIC before any target is created
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/res/ui)

#Generate the executable
if(WIN32)
	add_executable(
		${PROJECT_NAME}
		WIN32
		main.cpp)
		
	set_target_properties(${PROJECT_NAME}
		PROPERTIES
		LINK_FLAGS
		/SUBSYSTEM:CONSOLE)
		
		
else()
	add_executable(
		${PROJECT_NAME}
		main.cpp)
		
endif()

#Add a source group for the main.cpp (files in the root in general)
source_group(
	TREE "${PROJECT_SOURCE_DIR}"
	FILES "main.cpp")

#SET HEADERS HERE:
#The necessary directory is prepended automatically
set(${PROJECT_NAME}_HEADERS 
	core/FileStructurizer.h
	core/FileStructScene.h
	core/FileStructView.h)

#SET SOURCE FILES HERE:
#The necessary BUILD_INTERFACE generator expression is prepended automatically
set(${PROJECT_NAME}_SOURCES 
	core/FileStructurizer.cpp
	core/FileStructScene.cpp
	core/FileStructView.cpp)

#SET UI FILES HERE
#The ui/ directory expression
#is automatically prepended later so don't add it here
set(${PROJECT_NAME}_UI_FILES 
	FileStructurizer.ui)

#SET QT RESOURCE FILES HERE:
#The necessary directory is prepended automatically
set(${PROJECT_NAME}_RESOURCES 
	FileStructurizer.qrc)

#Set the binary output directory for the created target
set_target_properties(
	${PROJECT_NAME}
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

#Set the C++ standard for the target
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

#Include the current directory into the target
target_include_directories(
	${PROJECT_NAME} 
	PRIVATE 
	${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/core)

#Add the source files
list(TRANSFORM ${PROJECT_NAME}_SOURCES PREPEND ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/)
target_sources(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_SOURCES})

#Group the source files
source_group(
	TREE "${PROJECT_SOURCE_DIR}"
	FILES ${${PROJECT_NAME}_SOURCES})

#Add the header files
list(TRANSFORM ${PROJECT_NAME}_HEADERS PREPEND ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/)
target_sources(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_HEADERS})

#Group the header files
source_group(
	TREE "${PROJECT_SOURCE_DIR}"
	FILES ${${PROJECT_NAME}_HEADERS})

#Add the UI files 
list(TRANSFORM ${PROJECT_NAME}_UI_FILES PREPEND ${CMAKE_SOURCE_DIR}/res/ui/)
target_sources(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_UI_FILES})

#Group the UI files
source_group(
	TREE "${PROJECT_SOURCE_DIR}"
	FILES ${${PROJECT_NAME}_UI_FILES})

#Add the Qt resource files
list(TRANSFORM ${PROJECT_NAME}_RESOURCES PREPEND ${CMAKE_SOURCE_DIR}/res/)
target_sources(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_RESOURCES})

#Group the resource files
source_group(
	TREE "${PROJECT_SOURCE_DIR}"
	FILES ${${PROJECT_NAME}_RESOURCES})

#Link the necessary libs
target_link_libraries(
	${PROJECT_NAME} 
	Qt::Widgets)
	
#windeployqt
if(WIN32)
	if(EXISTS ${Qt5InstallPath}/bin/windeployqt.exe)
		if(CMAKE_BUILD_TYPE MATCHES Release)
			set(BINARIES_TYPE --release)
			
		else()
			set(BINARIES_TYPE --debug)
			
		endif()
		
		add_custom_command(
			TARGET ${PROJECT_NAME}
			POST_BUILD
			COMMAND
				${Qt5InstallPath}/bin/windeployqt.exe ${BINARIES_TYPE} --no-translations --compiler-runtime --no-system-d3d-compiler
				--no-angle --no-webkit2 --no-quick-import $<TARGET_FILE:${PROJECT_NAME}>)
	else()
		message("Unable to find Qt5InstallPath=${Qt5InstallPath}")
	endif()
endif()