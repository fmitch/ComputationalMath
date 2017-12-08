add_library(fft STATIC
    fft.c
    fft.h
    )

target_include_directories(fft PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
