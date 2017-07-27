include_directories("../include")
add_library(Mock_Shape "Mock_Shape.cpp")

add_library(Mock_Edge "Mock_Edge.cpp")
target_link_libraries(Mock_Edge "Mock_Shape")

add_library(Mock_Face "Mock_Face.cpp")
target_link_libraries(Mock_Face "Mock_Shape" "Mock_Edge")

add_library(Mock_Box "Mock_Box.cpp")
target_link_libraries(Mock_Box "Mock_Shape" "Mock_Face")

add_library(MockObjectMaker "MockObjectMaker.cpp")
target_link_libraries(MockObjectMaker 
    "Mock_Box"
    )

add_executable(ShapeTester "ShapeTester.cpp")
target_link_libraries(ShapeTester "Mock_Shape")

add_executable(EdgeTester "EdgeTester.cpp")
target_link_libraries(EdgeTester "Mock_Edge")

add_executable(FaceTester "FaceTester.cpp")
target_link_libraries(FaceTester "Mock_Face")

add_executable(MockObjectMakerTester "MockObjectMakerTester.cpp")
target_link_libraries(MockObjectMakerTester
    MockObjectMaker
)

