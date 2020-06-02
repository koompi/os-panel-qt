set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES networkservice.cpp wifiapplet.cpp wifiitemmodel.cpp wifiitemcontainer.cpp)

set(HEADERS networkservice.h wifiapplet.h wifiitemmodel.h wifiitemcontainer.h)
find_package(Qt5 COMPONENTS Widgets Network Concurrent REQUIRED)

add_library(koompiwifi SHARED ${SOURCES} ${HEADERS})
target_include_directories(koompiwifi  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(koompiwifi PRIVATE Qt5::Widgets Qt5::Network Qt5::Concurrent)

