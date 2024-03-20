cmake_minimum_required(VERSION 3.20)
project(Design-Patterns CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

include_directories(
	./Definition
)

add_subdirectory(Simple_Factory)
add_subdirectory(Strategy)
