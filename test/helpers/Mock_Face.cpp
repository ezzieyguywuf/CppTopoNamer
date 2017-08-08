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
        myEdges.push_back(std::move(unique_ptr<IEdge>(new Mock::Edge(edge.getVal()))));
    }
}

Face::Face (const Face& aFace)
    : myValue(aFace.myValue)
{
    for (const auto& edge : aFace.myEdges)
    {
        const IEdge* tmpIEdge = edge.get();
        const Mock::Edge*  tmpMockEdge = static_cast<const Mock::Edge*>(tmpIEdge);
        myEdges.push_back(std::move(unique_ptr<IEdge>(new Mock::Edge(*tmpMockEdge))));
    }
}

Face::Face(Face&& aFace)
    : myValue(aFace.myValue), myEdges(std::move(aFace.myEdges))
{
    aFace.myValue = 0;
    aFace.myEdges.clear();
}

Face Face::operator=(const Face& aFace)
{
    myEdges.clear();
    for (const auto& edge : aFace.myEdges)
    {
        const IEdge* tmpIEdge = edge.get();
        const Mock::Edge*  tmpMockEdge = static_cast<const Mock::Edge*>(tmpIEdge);
        myEdges.push_back(std::move(unique_ptr<IEdge>(new Mock::Edge(*tmpMockEdge))));
    }
    myValue = aFace.myValue;
    return *this;
}

Face Face::operator=(Face&& aFace)
{
    if (this != & aFace)
    {
        myValue = 0;
        myEdges.clear();

        myValue = aFace.myValue;
        myEdges = std::move(aFace.myEdges);

        aFace.myValue = 0;
        aFace.myEdges.clear();
    }
    return *this;
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
    return myEdges;
}

int Face::getValue() const{
    return myValue;
}


void Face::changeEdge(int which, const Mock::Edge& newEdge)
{
    myEdges[which] = std::move(unique_ptr<IEdge>(new Mock::Edge(newEdge.getVal())));
}

void Face::changeEdge(int index, const unique_ptr<IEdge>& newIEdge)
{
    const Mock::Edge* newEdge = static_cast<const Mock::Edge*>(&newIEdge);
    this->changeEdge(index, *newEdge);
}

Mock::Edge Face::getEdge(int index)
{
    IEdge* tmpIEdge = myEdges[index].get();
    Mock::Edge*  tmpMockEdge = static_cast<Mock::Edge*>(tmpIEdge);
    Mock::Edge outEdge(*tmpMockEdge);
    return outEdge;
}
