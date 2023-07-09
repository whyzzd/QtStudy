cmake_minimum_required(VERSION 3.5)

project(Thread3 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

set(PROJECT_SOURCES
    main.cpp 
    
    threadimag.cpp
    threadimag.h
    
    widget.cpp
    widget.h
    widget.ui

)

add_executable(Thread3
    ${PROJECT_SOURCES}
)

target_link_libraries(Thread3 Qt5::Widgets)
