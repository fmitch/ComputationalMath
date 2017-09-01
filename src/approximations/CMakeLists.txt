add_library(approximations STATIC
	series.cpp
	series.hpp)

target_include_directories(approximations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
