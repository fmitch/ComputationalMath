add_library(matrix_solutions STATIC
    factoring.cpp
    factoring.hpp
    iterative.cpp
    iterative.hpp
    pariterative.cpp
    pariterative.hpp
	)

target_include_directories(matrix_solutions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
