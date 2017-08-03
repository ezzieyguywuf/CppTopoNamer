#include <Mock_Edge.h>

using Mock::Edge;

Edge::Edge(int value)
    : val(value)
{}

Edge::Edge(const Edge& anEdge)
    : val(anEdge.val)
{
}

Edge Edge::operator=(const Edge& anEdge)
{
    val = anEdge.val;
}

bool Edge::operator==(const Edge& anEdge) const
{
    return this->val == anEdge.val;
}

bool Edge::isFlipped(const Edge& anEdge) const
{
    return (*this) == anEdge;
}

int Edge::getVal() const{
    return this->val;
}
