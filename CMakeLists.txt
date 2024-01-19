cmake_minimum_required(VERSION 3.15)
project(RedisCppClient CXX)

set(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE hiredis)
