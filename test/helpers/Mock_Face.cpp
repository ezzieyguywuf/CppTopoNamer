#include <Face.h>
#include <Edge.h>

Face::Face (int value, std::vector<Edge> edges)
    : Shape(value), myEdges(edges), IShapeWithSubs(edges)
{}
