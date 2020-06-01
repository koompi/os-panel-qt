 
set(PLUGIN "actioncenter")


set(HEADERS
    kmpactioncenter.h
    kmpactioncenterview.h
    kmpactioncenterpopup.h
    kmpcontrolcenteritem.h
    actioncenterhome.h
    actionbutton.h
    actionsmbutton.h
    sessionbutton.h
    actionbuttonstyle.h
    actiondatetime.h
)
set(SOURCES
    kmpactioncenter.cpp
    kmpactioncenterview.cpp
    kmpactioncenterpopup.cpp
    kmpcontrolcenteritem.cpp
    actioncenterhome.cpp
    actiondatetime.cpp
)

set(UIS

)
BUILD_LXQT_PLUGIN(${PLUGIN})
