cmake_minimum_required(VERSION 3.5)

project(25_TcpInfoTrans LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

set(PROJECT_SOURCES
    main.cpp 
   


    myclient.cpp
    myclient.h
    myclient.ui

    myserver.cpp
    myserver.h
    myserver.ui

)

add_executable(25_TcpInfoTrans
    ${PROJECT_SOURCES}
)

target_link_libraries(25_TcpInfoTrans Qt5::Widgets Network)
