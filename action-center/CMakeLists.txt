set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES controlcenter.cpp controlcenteritem.cpp)

set(MOC_HEADERS controlcenter.h controlcenteritem.h)
set(CMAKE_PREFIX_PATH )
find_package(Qt5 COMPONENTS Widgets Network Concurrent REQUIRED)
find_package(kmpbluetooth)
find_package(koompiwifi)
find_package(koompisound)
find_package (brightness)
<<<<<<< HEAD
find_package (display)
add_library(actioncenter ${SOURCES} ${MOC_HEADERS})

target_include_directories(actioncenter PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(actioncenter PUBLIC koompibluetooth koompiwifi koompisound brightness display Qt5::Widgets Qt5::Network Qt5::Concurrent )
=======
find_package (locale)
add_library(actioncenter ${SOURCES} ${MOC_HEADERS})

target_include_directories(actioncenter PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(actioncenter PUBLIC koompibluetooth koompiwifi koompisound brightness locale Qt5::Widgets Qt5::Network Qt5::Concurrent )
>>>>>>> a5244a33f04b69a1e4ab66ca9f8f42b3a45f31e5

