#ifndef SolidManager_Primitive_HEADER
#define SolidManager_Primitive_HEADER

#include <ISolidManager.h>
#include <ISolid.h>
#include <IFace.h>
#include <IEdge.h>
#include <map>
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
            const unique_ptr<IEdge>& getEdgeByIndex(const unsigned int index) const override;
            const unique_ptr<ISolid>& getSolid() const override;
            void modifyUnderlyingSolid(
                    unique_ptr<ISolid> newSolid,
                    // each pair should be (old-face, new-face)
                    const vector<pair<unique_ptr<IFace>, unique_ptr<IFace>>>& modifiedFaces) const override;

        private:
            unique_ptr<ISolid> mySolid;
            // These two maps will allow consistent reference to the underlying topology
            // of `mySolid`. This will be done by ensuring that any time `mySolid`
            // changes, we are are keeping track of which `IFace` changes and update the
            // `faces` and `edges` map accordingly
            //
            // The key in these maps will be the constant reference that can be used
            // externally to get a consistent handle to the underlying mySolid topology.
            // In other words, faces[1] should always refer to the same topological Face
            // in mySolid.
            //
            // The value in these maps in the index to the vectors returned by
            // mySolid->getFaces() and mySolid->getEdges() respectively. This value will
            // change any time that mySolid changes. Any change to mySolid _must_ be
            // associated with a list of changed topological Faces. This list will be used
            // to update the values in these two maps.
            std::map<unsigned int, unsigned int> faces;
            std::map<unsigned int, unsigned int> edges;
    };
}
#endif //SolidManager_Primitive_HEADER
