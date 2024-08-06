

cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(USB-RELAY
  LANGUAGES CXX
  VERSION 1.0
)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(wxBUILD_SHARED OFF)


add_library(serial ${CMAKE_CURRENT_SOURCE_DIR}/src/serialib.cpp)
target_include_directories(serial PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


file(GLOB_RECURSE SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/example/relaycontrol.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/usbrelay.cpp
            )



add_executable(usbrelay ${SOURCES})

target_include_directories(usbrelay PUBLIC
                          ${CMAKE_CURRENT_SOURCE_DIR}/include
                          )
target_link_libraries(usbrelay PRIVATE serial)




