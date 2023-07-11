cmake_minimum_required(VERSION 3.0)

set(PROJECT_SOURCES 
                    main.cpp
                    scroller.cpp 
                    scroller.h
                    scrollervolume.cpp
                    scrollervolume.h
                    scrollercontrolregion.cpp
                    scrollercontrolregion.h
                    scrollerlight.cpp
                    scrollerlight.h
    )

project(Scroller VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Python REQUIRED Development)

add_executable(Scroller ${PROJECT_SOURCES})
target_link_libraries(Scroller Qt5::Core Qt::Gui Qt::Widgets Python::Python)
