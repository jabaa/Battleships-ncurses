cmake_minimum_required (VERSION 3.6.3)
project (Battleships)

set (CMAKE_CXX_STANDARD 14)

set (PROJECT_SOURCE_DIR src)
set (PROJECT_BINARY_DIR build)

find_package(Curses REQUIRED)

find_program(
  CLANG_TIDY_EXE
  NAMES "clang-tidy clang-tidy-5.0"
  DOC "Path to clang-tidy executable"
  )
if(NOT CLANG_TIDY_EXE)
  message(STATUS "clang-tidy not found.")
else()
  message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
  set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}" "-checks=*,-clang-analyzer-alpha.* -header-filter=.*")
endif()

include_directories(${CURSES_INCLUDE_DIR})
add_executable(Battleships src/main.cpp src/Battleships.cpp src/utils.cpp src/Field.cpp src/Ncurses.cpp src/Ncurses.h)

target_link_libraries(Battleships ${CURSES_LIBRARIES})

set_target_properties(
  Battleships PROPERTIES
  CXX_STANDARD_REQUIRED ON
  COMPILE_FLAGS "${WARNING_FLAGS}"
)

if(CLANG_TIDY_EXE)
  set_target_properties(
    Battleships PROPERTIES
    CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
  )
endif()
