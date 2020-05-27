set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES
    localeui.cpp
    localeui.h
    localecontrol.cpp
    localecontrol.h
    localeconfig.cpp
    localeconfig.h
    )
set(MOC_HEADERS
    localeui.cpp
    localeui.h
    localecontrol.cpp
    localecontrol.h
    localeconfig.cpp
    localeconfig.h
    )

find_package(Qt5 COMPONENTS Widgets  REQUIRED)
add_library(locale
    ${SOURCES}
    ${MOC_HEADERS}
    )

target_include_directories(locale PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(locale PRIVATE Qt5::Widgets )
