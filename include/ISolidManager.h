#ifndef ISolidManager_HEADER
#define ISolidManager_HEADER

#include <ISolid.h>
#include <IFace.h>
#include <IEdge.h>
#include <SolidManager_Types.h>

#include <memory>
#include <vector>
#include <utility>

using std::vector;
using std::pair;
using SolidManager::EdgeIndex;
using SolidManager::FaceIndex;

class ISolidManager
{
    public:
        FaceIndex getIndex(const unique_ptr<IFace>& aFace) const;
        EdgeIndex getIndex(const unique_ptr<IEdge>& anEdge) const;
        const unique_ptr<IEdge>& getEdge(const EdgeIndex index) const;
        const unique_ptr<IFace>& getFace(const FaceIndex index) const;
        const unique_ptr<ISolid>& getManagedSolid() const;
        void updateSolid(
                unique_ptr<ISolid> newSolid, 
                const vector<pair<FaceIndex, FaceIndex>>& modifiedFaces);

    private:
        virtual FaceIndex getFaceIndex(const unique_ptr<IFace>& aFace) const = 0;
        virtual EdgeIndex getEdgeIndex(const unique_ptr<IEdge>& anEdge) const = 0;
        virtual const unique_ptr<IFace>& getFaceByIndex(const FaceIndex index) const = 0;
        virtual const unique_ptr<IEdge>& getEdgeByIndex(const EdgeIndex index) const = 0;
        virtual const unique_ptr<ISolid>& getSolid() const = 0;
        virtual void modifyUnderlyingSolid(
                unique_ptr<ISolid> newSolid,
                const vector<pair<FaceIndex, FaceIndex>>& modifiedFaces) = 0;
};

FaceIndex ISolidManager::getIndex(const unique_ptr<IFace>& aFace) const
{
    return this->getFaceIndex(aFace);
}

EdgeIndex ISolidManager::getIndex(const unique_ptr<IEdge>& anEdge) const
{
    return this->getEdgeIndex(anEdge);
}

const unique_ptr<IEdge>& ISolidManager::getEdge(const EdgeIndex index) const
{
    return this->getEdgeByIndex(index);
}

const unique_ptr<IFace>& ISolidManager::getFace(const FaceIndex index) const
{
    return this->getFaceByIndex(index);
}

const unique_ptr<ISolid>& ISolidManager::getManagedSolid() const
{
    return this->getSolid();
}

void ISolidManager::updateSolid(
        unique_ptr<ISolid> newSolid, 
        const vector<pair<FaceIndex, FaceIndex>>& modifiedFaces)
{
    this->modifyUnderlyingSolid(std::move(newSolid), modifiedFaces);
}

#endif //ISolidManager_HEADER
