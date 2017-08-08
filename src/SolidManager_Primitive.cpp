#include <SolidManager_Primitive.h>

using SolidManager::Primitive;
using std::vector;
using std::unique_ptr;

Primitive::Primitive(unique_ptr<ISolid> aSolid)
    : mySolid(std::move(aSolid))
{
    unsigned int i=0;
    const vector<unique_ptr<IFace>>& faces = mySolid->getFaces();
    const vector<unique_ptr<IEdge>>& edges  = mySolid->getEdges();

    for (i = 0; i < faces.size(); ++i) {
        faceIndices.push_back(i);
    }

    for (i = 0; i < edges.size(); ++i) {
        edgeIndices.push_back(i);
    }
}

unsigned int Primitive::getFaceIndex(const unique_ptr<IFace>& aFace) const
{
    const vector<unique_ptr<IFace>>& realFaceVector = mySolid->getFaces();
    for (int i = 0 ; i < realFaceVector.size(); ++i)
    {
        unsigned int checkIndex = faceIndices[i];
        if (aFace == realFaceVector[checkIndex]){
            return i;
        }
    }
    return -1;
}

unsigned int Primitive::getEdgeIndex(const unique_ptr<IEdge>& anEdge) const
{
    const vector<unique_ptr<IEdge>>& realEdgeVector = mySolid->getEdges();
    for (int i = 0; i < realEdgeVector.size() ; ++i)
    {
        unsigned int checkIndex = edgeIndices[i];
        if (*anEdge == *(realEdgeVector[checkIndex]))
        {
            return i;
        }
    }
    return -1;
}

const unique_ptr<IEdge>& Primitive::getEdgeByIndex(const unsigned int index) const
{
    return mySolid->getEdges()[index];
}

const unique_ptr<ISolid>& Primitive::getSolid() const
{
    return this->mySolid;
}
