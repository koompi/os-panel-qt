set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    bluetoothui.cpp
    bluetoothitem.cpp
    bluetoothservice.cpp
    process.cpp
    )
#set(UIS pair.ui)
#QT5_WRAP_UI( UI_HEADERS ${UIS} )
set(MOC_HEADERS
    bluetoothui.h
    bluetoothservice.h
    bluetoothitem.h
    process.h
    )
set(RESOURCE Resources.qrc)
find_package(Qt5 COMPONENTS Widgets Concurrent Bluetooth  REQUIRED)
add_library(koompibluetooth
      ${SOURCES}
      ${MOC_HEADERS}
      ${RESOURCE}
)

target_include_directories(koompibluetooth PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(koompibluetooth PRIVATE Qt5::Widgets Qt5::Bluetooth Qt5::Concurrent )

