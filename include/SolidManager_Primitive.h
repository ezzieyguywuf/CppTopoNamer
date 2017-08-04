#ifndef SolidManager_Primitive_HEADER
#define SolidManager_Primitive_HEADER

#include <ISolidManager.h>
#include <ISolid.h>
#include <IFace.h>
#include <IEdge.h>
#include <vector>
#include <memory>

using std::unique_ptr;

namespace SolidManager{
class Primitive : public ISolidManager
    {
        public:
            Primitive(unique_ptr<ISolid> aSolid);
            unsigned int getFaceIndex(const unique_ptr<IFace>& aFace) const override;
            unsigned int getEdgeIndex(const unique_ptr<IEdge>& anEdge) const override;
            const unique_ptr<ISolid>& getSolid() const override;

        private:
            unique_ptr<ISolid> mySolid;
            // these hold indices to the vectors returned by mySolid->getFaces() and
            // mySolid->getEdges(), respectively. The index of a value in these vectors
            // will always point to the same face. In other words:
            // mySolid->getFaces()[faceIndices[0]] will always point to the same face.
            std::vector<unsigned int> faceIndices;
            std::vector<unsigned int> edgeIndices;
    };
}
#endif //SolidManager_Primitive_HEADER
