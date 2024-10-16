cmake_minimum_required(VERSION 3.5)

project(Phonebook VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the path to your icon file
set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/icon1.png")


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        phonebook.h
        phonebook.cpp
        icon1.png
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ProjectQT
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(ProjectQT SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(ProjectQT
            ${PROJECT_SOURCES}
        )
    endif()
endif()


# Set the icon as a resource for the application
target_sources(ProjectQT PRIVATE ${APP_ICON_RESOURCE_WINDOWS})


target_link_libraries(ProjectQT PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)  # Linked against Sql module


set_target_properties(ProjectQT PROPERTIES
    WIN32_EXECUTABLE TRUE
    WIN32_EXECUTABLE YES
    LINK_FLAGS "-ICON:${APP_ICON_RESOURCE_WINDOWS}"
    OUTPUT_NAME "Phonebook"
)

install(TARGETS ProjectQT
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ProjectQT)
endif()
