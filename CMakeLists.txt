cmake_minimum_required(VERSION 3.20)
project(spic_poc_box2d)

set(CMAKE_CXX_STANDARD 20)

set(BOX2D_INCLUDE_DIR  ${PROJECT_SOURCE_DIR}/box2d-master/include)

include_directories(${PROJECT_SOURCE_DIR}/SDL2-2.0.16/include)
link_directories(${PROJECT_SOURCE_DIR}/SDL2-2.0.16/lib/x64)

include_directories(${PROJECT_SOURCE_DIR}/box2d-2.4.1/include)
link_directories(${PROJECT_SOURCE_DIR}/box2d-2.4.1/build/bin/Debug)

add_executable(spic_poc_box2d main.cpp)

target_link_libraries(spic_poc_box2d sdl2main sdl2)
target_link_libraries(spic_poc_box2d box2d)
