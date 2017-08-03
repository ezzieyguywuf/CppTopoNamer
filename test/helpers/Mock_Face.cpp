#include <Mock_Face.h>
#include <Mock_Edge.h>

using Mock::Face;
using Mock::Edge;
using std::unique_ptr;
using std::vector;

Face::Face (int value, vector<Mock::Edge> edges)
    : myValue(value) , myEdges(edges)
{
    this->buildSharedEdges();
}

Face::Face (const Face& aFace)
    : myValue(aFace.myValue), myEdges(aFace.myEdges)
{
    this->buildSharedEdges();
}

Face Face::operator=(const Face& aFace)
{
    myEdges = aFace.myEdges;
    myValue = aFace.myValue;
    this->buildSharedEdges();
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
    myEdges[which] = newEdge;
    unique_ptr<IEdge> newIEdge = unique_ptr<IEdge>(new Mock::Edge(newEdge.getVal()));
    //shareEdges[which] = std::move(newIEdge);
}

Mock::Edge Face::getEdge(int index)
{
    return myEdges[index];
}
void Face::buildSharedEdges()
{
    for (auto edge : myEdges)
    {
        shareEdges.push_back(std::move(unique_ptr<IEdge>(new Mock::Edge(edge.getVal()))));
    }
}
