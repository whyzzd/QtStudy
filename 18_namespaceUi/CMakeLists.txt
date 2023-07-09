cmake_minimum_required(VERSION 3.5)

project(18_namespaceUi LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp 
    
    mywidget.cpp
    mywidget.h
    
    widget.cpp
    widget.h
)

add_executable(18_namespaceUi
    ${PROJECT_SOURCES}
)

target_link_libraries(18_namespaceUi PRIVATE Qt5::Widgets)
