cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project(CppTopoNamerTests)

set(OCC_INCLUDE "/home/wolfie/Program/FreeCAD_dev/opencascade-7.1.0/inc")
set(OCC_LIBRARIES "/home/wolfie/Program/FreeCAD_dev/opencascade-7.1.0/build/lin64/gcc/libd")
set(FAKEIT_INCLUDE "/home/wolfie/Program/FreeCAD_dev/CppTopoNamer/FakeIt/include")
set(FAKEIT_CONFIG_DIR "/home/wolfie/Program/FreeCAD_dev/CppTopoNamer/FakeIt/config/boost")

include_directories(
    "include"
    ${OCC_INCLUDE}
    ${FAKEIT_INCLUDE}
    ${FAKEIT_CONFIG_DIR}
)
link_directories(
    ${OCC_LIBRARIES}
    )

set(CTEST_ENVIRONMENT CTEST_OUTPUT_ON_FAILURE=1)
enable_testing()

add_subdirectory("src")
add_subdirectory("test")
