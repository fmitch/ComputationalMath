add_library(approximations STATIC
    derivative.cpp
    derivative.hpp
    polynomial.cpp
    polynomial.hpp
    roots.cpp
    roots.hpp
	series.cpp
	series.hpp)

target_include_directories(approximations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
