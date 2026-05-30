cmake_minimum_required(VERSION 3.15)

project(sendy)

add_executable(sendy
    src/main.cpp
)

target_include_directories(sendy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
