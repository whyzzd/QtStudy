cmake_minimum_required(VERSION 3.5)

project(16_QFileSystemModel1.3 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp 
    mylabel.cpp
    mylabel.h
    mylabel.ui 
    mytreeview2.cpp
    mytreeview2.h
    mytreeview2.ui  
    mywidget.cpp
    mywidget.h
    mywidget.ui
)

add_executable(16_QFileSystemModel1.3
    ${PROJECT_SOURCES}
)

target_link_libraries(16_QFileSystemModel1.3 PRIVATE Qt5::Widgets)
