#include <SolidManager_Primitive.h>

using SolidManager::Primitive;
using SolidManager::FaceIndex;
using SolidManager::EdgeIndex;
using std::vector;
using std::unique_ptr;

Primitive::Primitive(unique_ptr<ISolid> aSolid)
    : mySolid(std::move(aSolid))
{
    unsigned int i=0;

    for (i = 0; i < mySolid->getFaces().size(); ++i) {
        faces.insert(std::make_pair(FaceIndex(i), i));
    }

    //for (i = 0; i < mySolid->getEdges().size(); ++i) {
        //edges.insert(std::make_pair(EdgeIndex(i), i));
    //}
}

FaceIndex Primitive::getFaceIndex(const unique_ptr<IFace>& aFace) const
{
    for (auto pair : faces){
        const unique_ptr<IFace>& checkFace = mySolid->getFaces()[pair.second];
        if (*checkFace == *aFace)
            return FaceIndex(pair.first);
    }
    // TODO: throw an error? warn user?
    return FaceIndex();
}

EdgeIndex Primitive::getEdgeIndex(const unique_ptr<IEdge>& anEdge) const
{
    //for (auto pair : edges){
        //const unique_ptr<IEdge>& checkEdge = mySolid->getEdges()[pair.second];
        //if (*checkEdge == *anEdge)
            //return EdgeIndex(pair.first);
    //}
    // TODO: throw an error? warn user?
    return EdgeIndex();
}

//const unique_ptr<IEdge>& Primitive::getEdgeByIndex(const EdgeIndex index) const
//{
    //return mySolid->getEdges()[index.get()];
//}

const unique_ptr<ISolid>& Primitive::getSolid() const
{
    return this->mySolid;
}

void Primitive::modifyUnderlyingSolid(
        unique_ptr<ISolid> newSolid,
        const vector<pair<unique_ptr<IFace>, unique_ptr<IFace>>>& modifiedFaces) const
{

}
