add_library(approximations STATIC
    polynomial.cpp
    polynomial.hpp
    roots.hpp
    )

target_include_directories(approximations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
