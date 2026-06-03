cmake_minimum_required(VERSION 3.16)

project(sendy)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(nlohmann_json REQUIRED)

qt_standard_project_setup()

set(ENGINE_SOURCES
    # UI
    src/ui/MainWindow.cpp

    # Logger
    src/profiling/ConsoleLogger.cpp
    src/profiling/FileLogger.cpp
    src/profiling/LoggerManager.cpp
    src/profiling/UILogger.cpp
)

add_library(Engine
    ${ENGINE_SOURCES}
)

target_include_directories(Engine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Engine PRIVATE
    Qt6::Widgets
    nlohmann_json::nlohmann_json
)

add_executable(sendy
    src/main.cpp
)

target_include_directories(sendy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(sendy PRIVATE
    Engine
     Qt6::Widgets
)

if(WIN32)
    get_target_property(_qt_executable_dir Qt6::Core LOCATION)
    get_filename_component(_qt_bin_dir "${_qt_executable_dir}" DIRECTORY)

    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

    if(WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET sendy POST_BUILD
            COMMAND "${WINDEPLOYQT_EXECUTABLE}" "$<TARGET_FILE:sendy>"
            COMMENT "Füge Qt-DLLs automatisch hinzu..."
        )
    endif()
endif()