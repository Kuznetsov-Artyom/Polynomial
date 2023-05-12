CMAKE_MINIMUM_REQUIRED(VERSION 3.25.0)

project(polynomial)

include_directories(./headers)
include_directories(./sources)

set(SRC sources/Polynomial.cpp)
set(HDR headers/List.hpp headers/Monom.hpp headers/Polynomial.hpp)

add_library(main_lib ${SRC} ${HDR})

add_executable(polynomial main.cpp)
target_link_libraries(polynomial main_lib)