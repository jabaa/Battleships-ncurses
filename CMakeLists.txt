cmake_minimum_required (VERSION 3.6.3)
project (Battleships)

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy-5.0"
    DOC "Path to clang-tidy executable"
)
if(NOT CLANG_TIDY_EXE)
    message(STATUS "clang-tidy not found.")
else()
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}" "-checks=*,-clang-analyzer-alpha.* -header-filter=.*")
endif()

include_directories(${CONAN_INCLUDE_DIRS_NCURSES})
add_executable(Battleships src/main.cpp src/Battleships.cpp src/Battleships.h src/utils.cpp src/utils.h src/Field.cpp src/Field.h src/Ncurses.cpp src/Ncurses.h src/SettingField.cpp src/SettingField.h)

target_link_libraries(Battleships ${CONAN_LIBS_NCURSES})

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
