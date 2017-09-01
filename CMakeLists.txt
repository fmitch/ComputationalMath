cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_CXX_STANDARD 14)
project(Math4610 VERSION 0.1.0)
if(CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_CONFIGURATION_TYPES Debug Release)
	set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
	  "Set the configurations to what we need" FORCE
	   )
endif()
if("$CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()
add_subdirectory(src)
add_subdirectory(test)
