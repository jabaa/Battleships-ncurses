include_directories(${CONAN_INCLUDE_DIRS_NCURSES})

add_library(UiNcurses SHARED Ui.h Ncurses/Ui.cpp Ncurses/Ui.h Ncurses/Ncurses.cpp Ncurses/Ncurses.h Ui.cpp Ncurses/Game.cpp Ncurses/Game.h Ncurses/LocalGame.cpp Ncurses/LocalGame.h)

target_link_libraries(UiNcurses Application)
target_link_libraries(UiNcurses ${CONAN_LIBS_NCURSES})

set_target_properties(
        UiNcurses PROPERTIES
        CXX_STANDARD_REQUIRED ON
        COMPILE_FLAGS "${WARNING_FLAGS}"
)

if(CLANG_TIDY_EXE)
    set_target_properties(
            UiNcurses PROPERTIES
            CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
    )
endif()