cmake_minimum_required(VERSION 4.0)
project(MySTL)

set(CMAKE_CXX_STANDARD 20)

add_executable(MySTL main.cpp
        Vecteur.h

        List.h
        Digraph.h
        AlgorithmesDigraphes.cpp
)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.x
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(tests)