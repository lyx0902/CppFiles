cmake_minimum_required(VERSION 3.28)
project(test1)
include_directories(${PROJECT_SOURCE_DIR}/CSPCode ${PROJECT_SOURCE_DIR}/LuoGuProgram ${PROJECT_SOURCE_DIR}/LuoGuBasic)
set(CMAKE_CXX_STANDARD 26)

add_executable(test1 ${PROJECT_SOURCE_DIR}/CSPCode/CSP33_01.cpp)
