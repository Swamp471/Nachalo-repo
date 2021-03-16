cmake_minimum_required(VERSION 3.5)

project(categorizer3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(categorizer3 include/categorizer3.hpp src/categorizer3.cpp)

target_include_directories(categorizer3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
