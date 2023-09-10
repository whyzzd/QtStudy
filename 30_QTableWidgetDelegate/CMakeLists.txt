cmake_minimum_required(VERSION 3.5)

project(30_QTableWidgetDelegate LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp 
   
    widget.cpp
    widget.h
    widget.ui
	
	spinboxdelegate.h
	spinboxdelegate.cpp
	

)

add_executable(30_QTableWidgetDelegate
	${PROJECT_SOURCES}
)

target_link_libraries(30_QTableWidgetDelegate Qt5::Widgets)
