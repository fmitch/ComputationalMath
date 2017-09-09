add_library(approximations STATIC
    polynomial.cpp
    polynomial.hpp
	series.cpp
	series.hpp)

target_include_directories(approximations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
