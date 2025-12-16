# cmake_minimum_required(VERSION 4.0)
set(CMAKE_CXX_COMPILER g++)
cmake_minimum_required(VERSION 3.28)
project(newproject CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
    message("*** Build type not set.  defaulting to Debug")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options( 
        -g3 
        -Og
        -std=c++23
        -fsanitize=address,undefined,leak
        -fno-omit-frame-pointer 
        -Wall
        -Wconversion
        -Wpedantic
        -Werror
        -Wextra
        -Wno-interference-size
    )
else()
    add_compile_options(
        -O3
        -std=c++23
        -Wall
        -Wconversion
        -Wpedantic
        -Werror
        -Wextra
        -march=native
        -Wall
    )
endif()


# Compiler flags and other goodies
add_link_options(-Wno-interference-size -fsanitize=address,undefined,leak)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE COMMON_SRC
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

include_directories("${CMAKE_SOURCE_DIR}/include")
add_executable(myfirstmain ${COMMON_SRC})

set_target_properties(myfirstmain PROPERTIES
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED YES
)

# Put all executables in the same directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Convention for executables and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

message("************************************************************")
message("**** Building in ${CMAKE_BUILD_TYPE} mode ")
message("************************************************************")