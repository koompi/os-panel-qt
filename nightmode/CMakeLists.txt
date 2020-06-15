set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES
    nightmodecontrol.cpp
    nightmodecontrol.h
    )
set(MOC_HEADERS
    nightmodecontrol.cpp
    nightmodecontrol.h
    )
find_package(Qt5 COMPONENTS Widgets Concurrent  REQUIRED)
add_library(nightmode
      ${SOURCES}
      ${MOC_HEADERS}

)

target_include_directories(nightmode PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(nightmode PRIVATE Qt5::Widgets Qt5::Concurrent )
