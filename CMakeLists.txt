cmake_minimum_required(VERSION 3.27)
project(sebox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "-DCMAKE_PREFIX_PATH=/usr/local/Cellar/qt/gcc_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Gui
        Widgets
        REQUIRED)

add_executable(sebox main.cpp
        src/UI/Main_Window.h
        #        src/UI/Main_Window.cpp
#        src/Core/App_Manager.cpp
#        src/Core/Logger.cpp
#        src/Core/Settings_Manager.cpp
#        src/Utilities/File_Utils.cpp
#        src/Utilities/String_Utils.cpp
#        src/Utilities/Date_Utils.cpp
#        src/Services/Authentication_Service.cpp
#        src/Data_Models/Card.cpp
#        src/Data_Models/Data_Validator.cpp
#        src/Database/Database_Manager.cpp
#        src/Database/Database_Handler.cpp
#        src/Database/Schema_Manager.cpp
#        src/UI/Card_Editor.cpp
#        src/UI/Review_Session.cpp
#        src/UI/Message_Box.cpp
#        src/Data_Models/User_Preferences.cpp
#        src/Data_Models/Data_Model.cpp
)

# Тестирование
add_executable(test
        tests/Core_Tests.cpp
        tests/Database_Tests.cpp
        tests/Logger_Test.cpp
        tests/Service_Tests.cpp
        tests/UI_Tests.cpp)

target_link_libraries(sebox
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

