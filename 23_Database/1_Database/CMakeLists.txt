cmake_minimum_required(VERSION 3.5)

project(1_Database LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Network Sql REQUIRED)

set(PROJECT_SOURCES
    main.cpp 
   
    widget.cpp
    widget.h
    widget.ui

)

add_executable(1_Database
    ${PROJECT_SOURCES}
)

target_link_libraries(1_Database Qt5::Widgets Qt5::Network Qt5::Sql)
