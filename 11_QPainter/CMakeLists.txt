cmake_minimum_required(VERSION 3.5)

project(11_QPainter LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    res.qrc

)

add_executable(11_QPainter
    ${PROJECT_SOURCES}
)

target_link_libraries(11_QPainter PRIVATE Qt5::Widgets)
