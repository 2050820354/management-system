cmake_minimum_required(VERSION 3.16)
project(task)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(task
        main.cpp
        human.cpp human.h
        student.cpp student.h
        teacher.cpp teacher.h
        school.cpp school.h
        utils.h utils.cpp)

add_executable(test
        test.cpp
        human.cpp human.h
        student.cpp student.h
        teacher.cpp teacher.h
        school.cpp school.h
        utils.h utils.cpp)

