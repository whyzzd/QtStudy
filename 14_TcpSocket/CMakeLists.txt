cmake_minimum_required(VERSION 3.5)

project(14_TcpSocket LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

set(PROJECT_SOURCES
    main.cpp 
    clientwidget.cpp
    clientwidget.h
    clientwidget.ui
    
    serverwidget.cpp
    serverwidget.h
    serverwidget.ui
    
)

add_executable(14_TcpSocket
    ${PROJECT_SOURCES}
)

target_link_libraries(14_TcpSocket PRIVATE Qt5::Widgets Qt5::Network)
