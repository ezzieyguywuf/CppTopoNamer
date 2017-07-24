add_library(Mock_Shape "Mock_Shape.cpp")

add_library(Mock_Edge "Mock_Edge.cpp")
target_link_libraries(Mock_Edge "Mock_Shape")

add_library(Mock_Face "Mock_Face.cpp")
target_link_libraries(Mock_Face "Mock_Shape" "Mock_Edge")

add_library(MockObjectMaker "MockObjectMaker.cpp")
target_link_libraries(MockObjectMaker 
    "Mock_Shape" 
    "Mock_Edge"
    "Mock_Face")

