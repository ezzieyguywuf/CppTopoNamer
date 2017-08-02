#include <Mock_Edge.h>

using Mock::Edge;

Edge::Edge(int value)
    : val(value)
{}

bool Edge::operator==(const Edge& anEdge) const
{
    return this->val == anEdge.val;
}

bool Edge::isFlipped(const Edge& anEdge) const
{
    return (*this) == anEdge;
}
