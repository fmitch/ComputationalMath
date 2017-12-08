add_library(error STATIC
	error.cpp
	error.hpp
	maceps.cpp
	maceps.hpp
	)

target_include_directories(error PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
