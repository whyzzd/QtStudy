cmake_minimum_required(VERSION 3.5)

project(27_QTranslator LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp 
   
    widget.cpp
    widget.h
    widget.ui

)

add_executable(27_QTranslator
    ${PROJECT_SOURCES}
)

target_link_libraries(27_QTranslator Qt5::Widgets)
