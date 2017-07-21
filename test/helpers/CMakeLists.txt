add_library(Mock_TopoDS_Shape "Mock_TopoDS_Shape.cpp")

add_library(Mock_TopoDS_Edge "Mock_TopoDS_Edge.cpp")
target_link_libraries(Mock_TopoDS_Edge "Mock_TopoDS_Shape")

add_library(Mock_TopoDS_Face "Mock_TopoDS_Face.cpp")
target_link_libraries(Mock_TopoDS_Face "Mock_TopoDS_Shape")

add_library(MockObjectMaker "MockObjectMaker.cpp")
target_link_libraries(MockObjectMaker 
    "Mock_TopoDS_Shape" 
    "Mock_TopoDS_Edge"
    "Mock_TopoDS_Face")

