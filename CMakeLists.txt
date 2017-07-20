cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH "bin")
set(LIBRARY_OUTPUT_PATH "lib")

project(CppTopoNamerTests)

include_directories(
    "include"
    "/home/wolfie/Program/FreeCAD_dev/opencascade-7.1.0/inc"
)
link_directories(
    "/home/wolfie/Program/FreeCAD_dev/opencascade-7.1.0/build/lin64/gcc/libd"
    )

add_subdirectory("src")
add_subdirectory("test")
