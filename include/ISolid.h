#ifndef ISolid_HEADER
#define ISolid_HEADER

#include <IFace.h>
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

class ISolid
{
    public:
        ~ISolid(){};
        const vector<unique_ptr<IFace>>& getFaces() const;
        const vector<unique_ptr<IEdge>>& getEdges() const;

    private:
        virtual const vector<unique_ptr<IFace>>& getFaceVector() const = 0;
        virtual const vector<unique_ptr<IEdge>>& getEdgeVector() const = 0;
};

const vector<unique_ptr<IFace>>& ISolid::getFaces() const
{
    return this->getFaceVector();
}

const vector<unique_ptr<IEdge>>& ISolid::getEdges() const
{
    return this->getEdgeVector();
}

#endif //ISolid_HEADER
