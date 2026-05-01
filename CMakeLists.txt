cmake_minimum_required(VERSION 4.0)
project(learncpp_quizzes)

set(CMAKE_CXX_STANDARD 20)

add_executable(learncpp_quizzes src/main.cpp
        src/quiz1.cpp
        include/quiz1.h
        include/quiz2.h
        src/quiz2.cpp
        src/quiz4.cpp
        include/quiz4.h
        include/quiz_registry.h
        src/quiz5.cpp
        include/quiz5.h)
