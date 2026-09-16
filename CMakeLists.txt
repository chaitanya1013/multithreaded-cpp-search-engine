cmake_minimum_required(VERSION 3.16)

project(MultithreadedCppSearchEngine
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(search_engine
    src/main.cpp
    src/DocumentParser.cpp
    src/DocumentReader.cpp
    src/InvertedIndex.cpp
)

target_include_directories(search_engine PRIVATE
    include
)

target_compile_options(search_engine PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
