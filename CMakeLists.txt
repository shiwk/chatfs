cmake_minimum_required(VERSION 3.23)

project(chatfs)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
if(FUSE_INC_DIR STREQUAL "")
    message(SEND_ERROR "FUSE_INC_DIR cannot be empty")
endif()

# include_directories(${FUSE_INC_DIR})

set(SRC_CH_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/mem)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${SRC_CH_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/chatting/*.cpp)

find_package(nlohmann_json 3.2.0 REQUIRED)

# link_directories(${FUSE_LIB_DIR})
add_executable( chatfs
        ${SOURCES}
        ${HEADERS})

message(STATUS "FUSE_LIB_DIR: ${FUSE_LIB_DIR}")

target_link_libraries(chatfs PRIVATE fuse curl nlohmann_json::nlohmann_json)