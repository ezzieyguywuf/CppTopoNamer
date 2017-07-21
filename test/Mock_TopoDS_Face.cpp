#include<Mock_TopoDS_Face.h>

using namespace mock;

TopoDS_Face::TopoDS_Face(unsigned int value)
    : TopoDS_Shape(value){
}

TopoDS_Face::TopoDS_Face(unsigned int value, std::vector<TopoDS_Edge> Edges)
    : TopoDS_Shape(value){
    this->Edges = Edges;
}

