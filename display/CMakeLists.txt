set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    displayui.cpp
    displayui.h
    controldisplay.cpp
    controldisplay.h
    )
set(MOC_HEADERS
    displayui.cpp
    displayui.h
    controldisplay.cpp
    controldisplay.h

    )

find_package(Qt5 COMPONENTS Widgets  REQUIRED)
add_library(display
      ${SOURCES}
      ${MOC_HEADERS}
)

target_include_directories(display PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(display PRIVATE Qt5::Widgets )
