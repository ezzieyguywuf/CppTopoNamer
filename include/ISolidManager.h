#ifndef ISolidManager_HEADER
#define ISolidManager_HEADER

#include <ISolid.h>
#include <IFace.h>
#include <IEdge.h>

#include <memory>
#include <vector>
#include <utility>

using std::vector;
using std::pair;

class ISolidManager
{
    public:
        unsigned int getIndex(const unique_ptr<IFace>& aFace) const;
        unsigned int getIndex(const unique_ptr<IEdge>& anEdge) const;
        const unique_ptr<IEdge>& getEdge(const unsigned int index) const;
        const unique_ptr<ISolid>& getManagedSolid() const;
        void updateSolid(
                unique_ptr<ISolid> newSolid, 
                const vector<pair<unique_ptr<IFace>, unique_ptr<IFace>>>& modifiedFaces) const;

    private:
        virtual unsigned int getFaceIndex(const unique_ptr<IFace>& aFace) const = 0;
        virtual unsigned int getEdgeIndex(const unique_ptr<IEdge>& anEdge) const = 0;
        virtual const unique_ptr<IEdge>& getEdgeByIndex(const unsigned int index) const = 0;
        virtual const unique_ptr<ISolid>& getSolid() const = 0;
        virtual void modifyUnderlyingSolid(
                unique_ptr<ISolid> newSolid,
                const vector<pair<unique_ptr<IFace>, unique_ptr<IFace>>>& modifiedFaces) const = 0;
};

unsigned int ISolidManager::getIndex(const unique_ptr<IFace>& aFace) const
{
    return this->getFaceIndex(aFace);
}

unsigned int ISolidManager::getIndex(const unique_ptr<IEdge>& anEdge) const
{
    return this->getEdgeIndex(anEdge);
}

const unique_ptr<IEdge>& ISolidManager::getEdge(const unsigned int index) const
{
    return this->getEdgeByIndex(index);
}

const unique_ptr<ISolid>& ISolidManager::getManagedSolid() const
{
    return this->getSolid();
}

void ISolidManager::updateSolid(
        unique_ptr<ISolid> newSolid, 
        const vector<pair<unique_ptr<IFace>, unique_ptr<IFace>>>& modifiedFaces) const
{
    this->modifyUnderlyingSolid(std::move(newSolid), modifiedFaces);
}

#endif //ISolidManager_HEADER
