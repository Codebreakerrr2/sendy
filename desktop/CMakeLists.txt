cmake_minimum_required(VERSION 3.16)

project(sendy)

# WICHTIG: Core und Gui mit aufnehmen, damit Qt seine internen Pfade freigibt!
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Das hier ist der moderne Qt6-Weg, der viele Standard-Sachen im Hintergrund regelt
qt_standard_project_setup()

add_executable(sendy
    src/main.cpp
    src/ui/MainWindow.cpp
)

target_include_directories(sendy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(sendy PRIVATE Qt6::Widgets)

# Automatisch windeployqt nach dem Build ausführen (Nur auf Windows)
if(WIN32)
    # Wir holen uns den Pfad direkt über die Eigenschaften von Qt6::Core
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