 
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES soundapplet.cpp soundservice.cpp)
set(MOC_HEADERS soundapplet.h soundservice.h)

find_package(Qt5 COMPONENTS Widgets Concurrent Multimedia  REQUIRED)
add_library(koompisound SHARED ${SOURCES} ${MOC_HEADERS} )

target_include_directories(koompisound PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(koompisound PRIVATE Qt5::Widgets Qt5::Multimedia Qt5::Concurrent)
