add_library(eigenvalues STATIC
    power.cpp
    power.hpp
    )

target_include_directories(eigenvalues PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
