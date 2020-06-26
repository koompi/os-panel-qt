 
set(PLUGIN "actioncenter")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTORCC ON)
set(HEADERS
    kmpactioncenter.h
    kmpactioncenterview.h
    kmpactioncenterpopup.h
    kmpcontrolcenteritem.h
    actioncenterhome.h
    actiondatetime.h
    actioncenterui.h
    airplane/airplaneconfig.h
)
set(SOURCES
    kmpactioncenter.cpp
    kmpactioncenterview.cpp
    kmpactioncenterpopup.cpp
    kmpcontrolcenteritem.cpp
    actioncenterhome.cpp
    actiondatetime.cpp
    airplane/airplaneconfig.cpp
)

set(UIS

)
BUILD_LXQT_PLUGIN(${PLUGIN})
