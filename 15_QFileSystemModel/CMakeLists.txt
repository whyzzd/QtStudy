cmake_minimum_required(VERSION 3.5)

project(15_QFileSystemModel LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp 
    filesystem.cpp
    filesystem.h
    filesystem.ui   
)

add_executable(15_QFileSystemModel
    ${PROJECT_SOURCES}
)

target_link_libraries(15_QFileSystemModel PRIVATE Qt5::Widgets)
