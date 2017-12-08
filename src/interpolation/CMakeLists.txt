add_library(interpolation STATIC
    interpolation.cpp
    interpolation.hpp
	)

target_include_directories(interpolation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
