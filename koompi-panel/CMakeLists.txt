set(CMAKE_AUTORCC ON)

set(RESOURCE Resources.qrc)

find_package(Qt5 COMPONENTS Widgets Network Concurrent Multimedia REQUIRED)
find_package(KF5WindowSystem REQUIRED)
find_package(koompisound)
find_package(actioncenter)
find_package(koompiwifi)

if(ANDROID)
  add_library(panel SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    timeapplet.cpp
    timeapplet.h
  )
else()
  add_executable(panel
    main.cpp
    mainwindow.cpp
    mainwindow.h
    timeapplet.cpp
    timeapplet.h
    ${RESOURCE}
  )
endif()

target_link_libraries(panel PRIVATE Qt5::Widgets
    KF5::WindowSystem
    Qt5::Network
    Qt5::Concurrent
    Qt5::Multimedia koompisound actioncenter koompiwifi)
