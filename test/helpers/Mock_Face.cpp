#include <Mock_Face.h>
#include <Mock_Edge.h>

using mock::Face;
using mock::Edge;

Face::Face (int value, std::vector<Edge> edges)
    : Shape(value), myEdges(edges), IShapeWithSubs(edges)
{}
