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

class ISolidManager
{
    public:
        SolidManager::FaceIndex getIndex(const unique_ptr<IFace>& aFace) const;
        SolidManager::EdgeIndex getIndex(const unique_ptr<IEdge>& anEdge) const;
        const unique_ptr<IEdge>& getEdge(const EdgeIndex index) const;
        const unique_ptr<ISolid>& getManagedSolid() const;
        void updateSolid(
                unique_ptr<ISolidManager> newSolid, 
                const vector<pair<SolidManager::FaceIndex, SolidManager::FaceIndex>>& modifiedFaces);

    private:
        virtual SolidManager::FaceIndex getFaceIndex(const unique_ptr<IFace>& aFace) const = 0;
        virtual SolidManager::EdgeIndex getEdgeIndex(const unique_ptr<IEdge>& anEdge) const = 0;
        virtual const unique_ptr<IEdge>& getEdgeByIndex(const EdgeIndex index) const = 0;
        virtual const unique_ptr<ISolid>& getSolid() const = 0;
        virtual void modifyUnderlyingSolid(
                unique_ptr<ISolidManager> newSolid,
                const vector<pair<SolidManager::FaceIndex, SolidManager::FaceIndex>>& modifiedFaces) = 0;
};

SolidManager::FaceIndex ISolidManager::getIndex(const unique_ptr<IFace>& aFace) const
{
    return this->getFaceIndex(aFace);
}

SolidManager::EdgeIndex ISolidManager::getIndex(const unique_ptr<IEdge>& anEdge) const
{
    return this->getEdgeIndex(anEdge);
}

const unique_ptr<IEdge>& ISolidManager::getEdge(const EdgeIndex index) const
{
    return this->getEdgeByIndex(index);
}

const unique_ptr<ISolid>& ISolidManager::getManagedSolid() const
{
    return this->getSolid();
}

void ISolidManager::updateSolid(
        unique_ptr<ISolidManager> newSolid, 
        const vector<pair<SolidManager::FaceIndex, SolidManager::FaceIndex>>& modifiedFaces)
{
    this->modifyUnderlyingSolid(std::move(newSolid), modifiedFaces);
}

#endif //ISolidManager_HEADER
