cmake_minimum_required(VERSION 3.27)
project(sebox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "-DCMAKE_PREFIX_PATH=/usr/local/Cellar/qt/gcc_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(sebox main.cpp)
target_link_libraries(sebox
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

