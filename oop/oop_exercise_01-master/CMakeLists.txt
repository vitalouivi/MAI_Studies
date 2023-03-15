cmake_minimum_required (VERSION 3.5)

project(lab1)

add_executable(oop_exercise_01
			   main.cpp
               lab1.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set_target_properties(oop_exercise_01 PROPERTIES CXX_STANDART 14 CXX_STANDART_REQUIRED ON)