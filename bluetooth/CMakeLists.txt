cmake_minimum_required(VERSION 3.15)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 COMPONENTS Widgets Bluetooth  REQUIRED)
add_library(kmp_bluetooth SHARED
      bluetoothui.cpp
      bluetoothui.h
      bluetoothscaner.cpp
      bluetoothscaner.h
      Resources.qrc
)


target_include_directories(kmp_bluetooth PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(kmp_bluetooth PRIVATE Qt5::Widgets Qt5::Bluetooth)

