cmake_minimum_required(VERSION 3.15)

project(sendy)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(sendy
    src/main.cpp
    src/ui/MainWindow.cpp
)

target_include_directories(sendy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(sendy PRIVATE Qt6::Widgets)