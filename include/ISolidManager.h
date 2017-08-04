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
        //const unique_ptr<ISolid>& getManagedSolid() const;

    private:
        virtual unsigned int getFaceIndex(const unique_ptr<IFace>& aFace) const = 0;
        virtual unsigned int getEdgeIndex(const unique_ptr<IEdge>& anEdge) const = 0;
        //virtual const unique_ptr<ISolid>& getSolid() const = 0;
};

unsigned int ISolidManager::getIndex(const unique_ptr<IFace>& aFace) const
{
    this->getFaceIndex(aFace);
}

unsigned int ISolidManager::getIndex(const unique_ptr<IEdge>& anEdge) const
{
    this->getEdgeIndex(anEdge);
}

//const unique_ptr<ISolid>& ISolidManager::getManagedSolid() const
//{
    //this->getSolid();
//}

#endif //ISolidManager_HEADER
