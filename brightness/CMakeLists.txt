set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    brightness.cpp
    brightness.h
    bluelight.cpp
    bluelight.h
    )
set(MOC_HEADERS
    brightness.cpp
    brightness.h
    bluelight.cpp
    bluelight.h

    )

find_package(Qt5 COMPONENTS Widgets  REQUIRED)
add_library(brightness
      ${SOURCES}
      ${MOC_HEADERS}
)

target_include_directories(brightness PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(brightness PRIVATE Qt5::Widgets )
