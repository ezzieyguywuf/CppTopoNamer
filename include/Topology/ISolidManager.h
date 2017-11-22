#ifndef ISolidManager_HEADER
#define ISolidManager_HEADER

#include <Topology/ISolid.h>
#include <Topology/IFace.h>
#include <Topology/IEdge.h>
#include <Managers/Types.h>

#include <memory>
#include <vector>
#include <utility>

using std::vector;
using std::pair;
using Manager::EdgeIndex;
using Manager::FaceIndex;

class ISolidManager
{
    public:
        inline FaceIndex getIndex(const unique_ptr<IFace>& aFace) const;
        inline EdgeIndex getIndex(const unique_ptr<IEdge>& anEdge) const;
        inline const unique_ptr<IEdge>& getEdge(const EdgeIndex index) const;
        inline const unique_ptr<IFace>& getFace(const FaceIndex index) const;
        inline const unique_ptr<ISolid>& getManagedSolid() const;
        inline void updateSolid(
                unique_ptr<ISolid> newSolid, 
                const vector<pair<FaceIndex, FaceIndex>>& modifiedFaces);
        inline bool isValid() const;

    private:
        virtual FaceIndex getFaceIndex(const unique_ptr<IFace>& aFace) const = 0;
        virtual EdgeIndex getEdgeIndex(const unique_ptr<IEdge>& anEdge) const = 0;
        virtual const unique_ptr<IFace>& getFaceByIndex(const FaceIndex index) const = 0;
        virtual const unique_ptr<IEdge>& getEdgeByIndex(const EdgeIndex index) const = 0;
        virtual const unique_ptr<ISolid>& getSolid() const = 0;
        virtual void modifyUnderlyingSolid(
                unique_ptr<ISolid> newSolid,
                const vector<pair<FaceIndex, FaceIndex>>& modifiedFaces) = 0;
        virtual bool checkValidity() const = 0;
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

bool ISolidManager::isValid() const
{
    return this->checkValidity();
}

#endif //ISolidManager_HEADER
