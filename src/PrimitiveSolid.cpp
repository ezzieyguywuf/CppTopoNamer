#include <Managers/PrimitiveSolid.h>
#include <stdexcept>

using Manager::PrimitiveSolid;
using Manager::FaceIndex;
using Manager::EdgeIndex;
using std::vector;
using std::unique_ptr;

PrimitiveSolid::PrimitiveSolid(unique_ptr<ISolid> aSolid)
    : mySolid(std::move(aSolid))
{
    unsigned int i=0;

    for (i = 0; i < mySolid->getFaces().size(); ++i) {
        faces.insert(std::make_pair(FaceIndex(i), i));
    }

    std::vector<FaceIndex> foundFaces;
    for (const auto& Edge : mySolid->getEdges()) {
        foundFaces.clear();
        for (const auto& keyValue : faces) {
            const auto& Face = mySolid->getFaces()[keyValue.second];
            for (const auto& FaceEdge : Face->getEdges()){
                if (*Edge == *FaceEdge){
                    foundFaces.push_back(keyValue.first);
                }
            }
        }
        if (foundFaces.size() < 2){
            throw std::runtime_error("Did not find two faces for this Edge");
        }
        EdgeIndex ind(edges.size());
        edges[ind] = std::make_pair(foundFaces[0], foundFaces[1]);
    }
}

FaceIndex PrimitiveSolid::getFaceIndex(const unique_ptr<IFace>& aFace) const
{
    for (auto pair : faces){
        const unique_ptr<IFace>& checkFace = mySolid->getFaces()[pair.second];
        if (*checkFace == *aFace)
            return FaceIndex(pair.first);
    }
    throw std::runtime_error("Was unable to find aFace in mySolid");
}

EdgeIndex PrimitiveSolid::getEdgeIndex(const unique_ptr<IEdge>& anEdge) const
{
    for (const auto& pair : edges){
        const auto& checkEdge = this->getEdgeByIndex(pair.first);
        if (*checkEdge == *anEdge)
            return EdgeIndex(pair.first);
    }
    throw std::runtime_error("Was unable to find anEdge in mySolid");
}

const unique_ptr<IEdge>& PrimitiveSolid::getEdgeByIndex(const EdgeIndex index) const
{
    const auto& faceIndices = edges.at(index);
    const auto& face1 = mySolid->getFaces()[faceIndices.first.get()];
    const auto& face2 = mySolid->getFaces()[faceIndices.second.get()];
    for (const auto& edge1 : face1->getEdges()){
        for (const auto& edge2 : face2->getEdges()){
            if (*edge1 == *edge2){
                return edge1;
            }
        }
    }
    throw std::runtime_error("For some reason, our two faces do not share an Edge");
}

const unique_ptr<IFace>& PrimitiveSolid::getFaceByIndex(const FaceIndex index) const
{
    return mySolid->getFaces()[faces.at(index)];
    //throw std::runtime_error("For some reason, our two faces do not share an Face");
}

const unique_ptr<ISolid>& PrimitiveSolid::getSolid() const
{
    return this->mySolid;
}

void PrimitiveSolid::modifyUnderlyingSolid(
        unique_ptr<ISolid> newSolid,
        const vector<pair<FaceIndex, FaceIndex>>& modifiedFaces) 
{
    mySolid = std::move(newSolid);
    for (const auto& indices : modifiedFaces)
    {
        faces[indices.first] = indices.second.get();
    }
}

bool isValid() const{
    if (mySolid == nullptr ||
        faces.empty() ||
        edges.empty())
    {
        return false;
    }
    return true;
}
