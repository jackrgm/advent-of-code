cmake_minimum_required(VERSION 3.25.1)
project(aoc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SRC_AOCCPP_2024 "src/aoccpp/2024*.cpp")

add_executable(aoccpp
	src/aoccpp/aoc.cpp
	src/aoccpp/yearbase.cpp
	${SRC_AOCCPP_2024}
)
