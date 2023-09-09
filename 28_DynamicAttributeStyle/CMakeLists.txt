cmake_minimum_required(VERSION 3.5)

project(28_DynamicAttributeStyle LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

qt5_add_resources(RESOURCE_FILES rc.qrc)

set(PROJECT_SOURCES
    main.cpp 
   
    widget.cpp
    widget.h
    widget.ui
	
	${RESOURCE_FILES}
)

add_executable(28_DynamicAttributeStyle
    ${PROJECT_SOURCES}
)

target_link_libraries(28_DynamicAttributeStyle Qt5::Widgets)
