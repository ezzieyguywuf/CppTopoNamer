#include <Mock_Edge.h>

using Mock::Edge;

Edge::Edge(int value)
    : val(value)
{}

Edge::Edge(const Edge& anEdge)
    : val(anEdge.val)
{
}

Edge::Edge(Edge&& anEdge)
    : val(anEdge.val)
{
    anEdge.val = 0;
}

Edge Edge::operator=(const Edge& anEdge)
{
    val = anEdge.val;
}

Edge Edge::operator=(Edge&& anEdge)
{
    if (this != &anEdge)
    {
        val = anEdge.val;
        anEdge.val = 0;
    }
    return *this;
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
