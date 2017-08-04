#include <SolidManager_Primitive.h>

using SolidManager::Primitive;
using std::vector;
using std::unique_ptr;

Primitive::Primitive(unique_ptr<ISolid> mySolid)
    : mySolid(std::move(mySolid))
{
    unsigned int i=0;
    //const vector<unique_ptr<IFace>>& faces = mySolid->getFaces();
    //const vector<unique_ptr<IEdge>> edges = mySolid->getEdges();

    //for (i = 0; i < faces.size(); ++i) {
        //faceIndices.push_back(i);
    //}

    //for (i = 0; i < edges.size(); ++i) {
        //edgeIndices.push_back(i);
    //}
}

unsigned int Primitive::getFaceIndex(const unique_ptr<IFace>& aFace) const
{
    const vector<unique_ptr<IFace>>& realFaceVector = mySolid->getFaces();
    for (int i; i < realFaceVector.size(); ++i)
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
    return -1;
}

const unique_ptr<ISolid>& Primitive::getSolid() const
{
    return this->mySolid;
}
