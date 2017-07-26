#include <Mock_Face.h>
#include <Mock_Edge.h>

using mock::Face;
using mock::Edge;

Face::Face (int value, std::vector<Edge> edges)
    : Shape(value), myEdges(edges)
{}

std::vector<Edge> Face::getEdges() const
{
    return this->myEdges;
}
