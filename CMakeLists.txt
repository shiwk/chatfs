cmake_minimum_required(VERSION 3.23)

project(chatfs)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
if(FUSE_INC_DIR STREQUAL "")
    message(SEND_ERROR "FUSE_INC_DIR cannot be empty")
endif()

include_directories(${FUSE_INC_DIR})

file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable( chatfs
        ${SOURCES}
        ${HEADERS})