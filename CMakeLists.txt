cmake_minimum_required (VERSION 3.6.3)
project (Battleships)

set (CMAKE_CXX_STANDARD 11)

set (PROJECT_SOURCE_DIR src)
set (PROJECT_BINARY_DIR build)

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})
add_executable(Battleships src/main.cpp src/Battleships.cpp src/utils.cpp)
target_link_libraries(Battleships ${CURSES_LIBRARIES})
