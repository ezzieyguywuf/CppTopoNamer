#include <Mock_Solid.h>
#include <IFace.h>
#include <algorithm>

using Mock::Solid;
using Mock::Edge;
using std::vector;
using std::unique_ptr;

Solid::Solid(vector<Face> faces)
{
    for (auto face : faces)
    {
        this->addFace(face);
    }
}

Solid::Solid(const Solid& aSolid)
{
    for (const auto& faceptr : aSolid.myFaces)
    {
        const IFace* tmpIFace = faceptr.get();
        const Face* tmpFace = static_cast<const Face*>(tmpIFace);
        this->addFace(*tmpFace);
    }
}

Solid::Solid(Solid&& aSolid)
    : myFaces(std::move(aSolid.myFaces)), myEdges(std::move(aSolid.myEdges))
{
}

Solid Solid::operator=(const Solid& aSolid)
{
    myFaces.clear();
    myEdges.clear();
    for (const auto& faceptr : aSolid.myFaces)
    {
        const IFace* tmpIFacePtr = faceptr.get();
        const Face* tmpFacePtr = static_cast<const Face*>(tmpIFacePtr);
        this->addFace(*tmpFacePtr);
    }
    return *this;
}

Solid Solid::operator=(Solid&& aSolid)
{
    if (this != &aSolid)
    {
        myFaces = std::move(aSolid.myFaces);
        myEdges = std::move(aSolid.myEdges);
    }
    return *this;
}

const vector<unique_ptr<IFace>>& Solid::getFaceVector() const
{
    return myFaces;
}

const vector<unique_ptr<IEdge>>& Solid::getEdgeVector() const
{
    return myEdges;
}

const unique_ptr<IFace>& Solid::getFace(int which) const{
    return myFaces[which];
}

// -------------------------------------------------------------
//                private methods
// -------------------------------------------------------------

bool Solid::checkEdge(const unique_ptr<IEdge>& anEdge) const
{
    for (const auto& edge : myEdges)
    {
        if (edge == anEdge)
        {
            return true;
        }
    }
    return false;
}

void Solid::addEdges(const vector<unique_ptr<IEdge>>& edges)
{
    for (const auto& edge : edges)
    {
        if (! this->checkEdge(edge))
        {
            Mock::Edge* tmpEdge = static_cast<Mock::Edge*>(edge.get());
            myEdges.push_back(std::move(unique_ptr<IEdge>(new Mock::Edge(tmpEdge->getVal()))));
        }
    }
}

void Solid::addFace(const Face& aFace)
{
    myFaces.push_back(std::move(unique_ptr<IFace>(new Mock::Face(aFace))));
    this->addEdges(aFace.getEdges());
}
