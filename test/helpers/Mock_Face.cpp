#include <Mock_Face.h>
#include <Mock_Edge.h>

using Mock::Face;
using Mock::Edge;
using std::unique_ptr;
using std::vector;

Face::Face (int value, vector<Mock::Edge> edges)
    : myValue(value) 
{
    for (auto edge : edges)
    {
        shareEdges.push_back(std::move(unique_ptr<IEdge>(new Mock::Edge(edge.getVal()))));
    }
}

bool Face::operator==(const Face& aFace) const
{
    return this->myValue == aFace.getValue();
}

bool Face::isFlipped(const Face& aFace) const
{
    return (*this) == aFace;
}

const vector<unique_ptr<IEdge>>& Face::getEdgeVector() const
{
    return shareEdges;
}

int Face::getValue() const{
    return myValue;
}

void Face::changeEdge(int which, Mock::Edge newEdge)
{
    shareEdges[which] = unique_ptr<IEdge>(new Mock::Edge(newEdge.getVal()));
}
