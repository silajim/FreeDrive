cmake_minimum_required(VERSION 3.14)

project(FreeDrives LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(FreeDrives STATIC
   freeDrives.h freeDrives.cpp
)
target_link_libraries(FreeDrives Qt${QT_VERSION_MAJOR}::Core)

target_include_directories(
  FreeDrives PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

install(TARGETS FreeDrives
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
