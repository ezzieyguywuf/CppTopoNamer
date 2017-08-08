#ifndef ISolidManager_HEADER
#define ISolidManager_HEADER

#include <ISolid.h>
#include <IFace.h>
#include <IEdge.h>
#include <memory>

class ISolidManager
{
    public:
        unsigned int getIndex(const unique_ptr<IFace>& aFace) const;
        unsigned int getIndex(const unique_ptr<IEdge>& anEdge) const;
        const unique_ptr<IEdge>& getEdge(const unsigned int index) const;
        const unique_ptr<ISolid>& getManagedSolid() const;

    private:
        virtual unsigned int getFaceIndex(const unique_ptr<IFace>& aFace) const = 0;
        virtual unsigned int getEdgeIndex(const unique_ptr<IEdge>& anEdge) const = 0;
        virtual const unique_ptr<IEdge>& getEdgeByIndex(const unsigned int index) const = 0;
        virtual const unique_ptr<ISolid>& getSolid() const = 0;
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

#endif //ISolidManager_HEADER
