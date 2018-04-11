cmake_minimum_required (VERSION 3.5.1)
project (Battleships)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_SOURCE_DIR src)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.8/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(CONANFILE conanfile.txt
       BASIC_SETUP
       BUILD missing)
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

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CONAN_INCLUDE_DIRS_GSL_MICROSOFT})

add_subdirectory(src/Application)
add_subdirectory(src/Ui)

add_executable(Battleships src/main.cpp)

target_link_libraries(Battleships UiNcurses)

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
