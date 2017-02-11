cmake_minimum_required(VERSION 2.8)
project(jsc-rescue-simulator)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

add_executable(simulator
    src/main.cpp
)
target_link_libraries(simulator Qt5::Core Qt5::Widgets)
