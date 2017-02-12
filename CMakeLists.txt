cmake_minimum_required(VERSION 2.8)
project(jsc-rescue-simulator)


set(CMAKE_AUTOMOC ON)
include_directories(${QT_INCLUDES})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Threads REQUIRED)

add_executable(simulator
    src/main.cpp
    src/PlaygroundView.cpp
    src/simulation.cpp
)
target_link_libraries(simulator Qt5::Core Qt5::Widgets ${CMAKE_THREAD_LIBS_INIT})
