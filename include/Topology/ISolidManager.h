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
        ~ISolidManager(){};
        inline FaceIndex getIndex(const IFace& aFace) const;
        inline EdgeIndex getIndex(const IEdge& anEdge) const;
        inline const IEdge& getEdge(const EdgeIndex index) const;
        inline const IFace& getFace(const FaceIndex index) const;
        inline const ISolid& getManagedSolid() const;
        inline void updateSolid(
                unique_ptr<ISolid> newSolid, 
                const vector<pair<FaceIndex, FaceIndex>>& modifiedFaces);
        inline bool isValid() const;

    private:
        virtual FaceIndex getFaceIndex(const IFace& aFace) const = 0;
        virtual EdgeIndex getEdgeIndex(const IEdge& anEdge) const = 0;
        virtual const IFace& getFaceByIndex(const FaceIndex index) const = 0;
        virtual const IEdge& getEdgeByIndex(const EdgeIndex index) const = 0;
        virtual const ISolid& getSolid() const = 0;
        virtual void modifyUnderlyingSolid(
                unique_ptr<ISolid> newSolid,
                const vector<pair<FaceIndex, FaceIndex>>& modifiedFaces) = 0;
        virtual bool checkValidity() const = 0;
};

FaceIndex ISolidManager::getIndex(const IFace& aFace) const
{
    return this->getFaceIndex(aFace);
}

EdgeIndex ISolidManager::getIndex(const IEdge& anEdge) const
{
    return this->getEdgeIndex(anEdge);
}

const IEdge& ISolidManager::getEdge(const EdgeIndex index) const
{
    return this->getEdgeByIndex(index);
}

const IFace& ISolidManager::getFace(const FaceIndex index) const
{
    return this->getFaceByIndex(index);
}

const ISolid& ISolidManager::getManagedSolid() const
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
