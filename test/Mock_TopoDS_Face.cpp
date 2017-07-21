#include<Mock_TopoDS_Face.h>

mock::TopoDS_Face::TopoDS_Face(unsigned int value)
    : mock::TopoDS_Shape(value){
}

mock::TopoDS_Face::TopoDS_Face(unsigned int value, std::vector<mock::TopoDS_Edge> Edges)
    : mock::TopoDS_Shape(value){
    this->Edges = Edges;
}

