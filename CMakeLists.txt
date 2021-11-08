cmake_minimum_required(VERSION 3.0)

project(SortingAlgorithms)

set(CMAKE_CXX_STANDARD 17)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML) # MUST BE CHANGED TO THE CORRECT SFML LOCATION
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(SortingAlgorithms main.cpp SortingAlgorithms.cpp SortingAlgorithms.h Field.cpp Field.h)

target_link_libraries(SortingAlgorithms sfml-graphics)