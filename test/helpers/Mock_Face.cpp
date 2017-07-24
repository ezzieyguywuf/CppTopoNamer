#include <Mock_Face.h>
#include <Mock_Edge.h>

using mock::Face;
using mock::Edge;

Face::Face (int value, std::vector<std::unique_pointer<Edge>> edges)
    : value(value), myEdges(edges)
{}

std::vector<std::unique_pointer<Edge>> getEdges() const
{
    return this->myEdges;
}
