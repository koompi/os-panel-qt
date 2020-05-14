 
set(PLUGIN "actioncenter")


set(HEADERS
    kmpactioncenter.h
    kmpactioncenterview.h
    kmpactioncenterpopup.h
)

set(SOURCES
    kmpactioncenter.cpp
    kmpactioncenterview.cpp
    kmpactioncenterpopup.cpp
)

set(UIS

)


BUILD_LXQT_PLUGIN(${PLUGIN})
