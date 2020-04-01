cmake_minimum_required(VERSION 3.5)

project(panel LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS -fsanitize=address)
# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

add_subdirectory(bluetooth)
add_subdirectory(wireless-fidelity)
add_subdirectory(action-center)
find_package(Qt5 COMPONENTS Widgets Network Concurrent Multimedia REQUIRED)
find_package(KF5WindowSystem)
find_package(kmp_bluetooth)

if(ANDROID)
  add_library(panel SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    wifiapplet.h
    wifiapplet.cpp
    timeapplet.cpp
    timeapplet.h
    soundapplet.cpp
    soundapplet.h
    controlcenter.h
    controlcenter.cpp
    controlcenteritem.cpp
    controlcenteritem.h
    wifiitemmodel.cpp
    wifiitemmodel.h
    wifiitemcontainer.cpp
    wifiitemcontainer.h
    soundservice.cpp
    soundservice.h
    networkservice.cpp
    networkservice.h
  )
else()
  add_executable(panel
    main.cpp
    mainwindow.cpp
    mainwindow.h
    wifiapplet.cpp
    wifiapplet.h
    timeapplet.cpp
    timeapplet.h
    soundapplet.cpp
    soundapplet.h
    controlcenter.cpp
    controlcenter.h
    controlcenteritem.cpp
    controlcenteritem.h
    wifiitemmodel.cpp
    wifiitemmodel.h
    wifiitemcontainer.cpp
    wifiitemcontainer.h
    soundservice.cpp
    soundservice.h
    networkservice.cpp
    networkservice.h
  )
endif()

target_link_libraries(panel PRIVATE Qt5::Widgets
    KF5::WindowSystem
    Qt5::Network
    Qt5::Concurrent
    Qt5::Multimedia kmp_bluetooth)
