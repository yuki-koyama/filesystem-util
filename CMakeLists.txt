cmake_minimum_required(VERSION 3.1)
project(filesystem-util CXX)
set(CMAKE_CXX_STANDARD 11)

file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/include/filesystem-util.hpp)
file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/filesystem-util.cpp)

add_library(filesystem-util STATIC ${headers} ${sources})
target_include_directories(filesystem-util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include FILES_MATCHING PATTERN "*.h*")
install(TARGETS filesystem-util ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
