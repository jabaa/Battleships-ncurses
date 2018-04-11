add_library(Application SHARED Application.cpp Application.h)

set_target_properties(
        Application PROPERTIES
        CXX_STANDARD_REQUIRED ON
        COMPILE_FLAGS "${WARNING_FLAGS}"
)

if(CLANG_TIDY_EXE)
    set_target_properties(
            Application PROPERTIES
            CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
    )
endif()