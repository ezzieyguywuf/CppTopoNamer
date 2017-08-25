#ifndef SolidManager_Primitive_HEADER
#define SolidManager_Primitive_HEADER

#include <ISolidManager.h>
#include <ISolid.h>
#include <IFace.h>
#include <IEdge.h>
#include <SolidManager_Types.h>
#include <map>
#include <vector>
#include <memory>
// for std::pair
#include <utility>

using std::unique_ptr;

namespace SolidManager{
    class Primitive : public ISolidManager
        {
            public:
                Primitive(unique_ptr<ISolid> aSolid);
                FaceIndex getFaceIndex(const unique_ptr<IFace>& aFace) const override;
                EdgeIndex getEdgeIndex(const unique_ptr<IEdge>& anEdge) const override;
                const unique_ptr<IEdge>& getEdgeByIndex(const EdgeIndex index) const override;
                const unique_ptr<ISolid>& getSolid() const override;
                void modifyUnderlyingSolid(
                        unique_ptr<ISolid> newSolid,
                        // each pair should be (old-face, new-face)
                        const std::vector<std::pair<unique_ptr<IFace>, unique_ptr<IFace>>>& modifiedFaces) const override;

            private:
                unique_ptr<ISolid> mySolid;
                // This map will allow consistent reference to the underlying topology
                // of `mySolid`. This will be done by ensuring that any time `mySolid`
                // changes, we are are keeping track of which `IFace` changes and update the
                // `faces` map accordingly.
                //
                // The key in this maps will be the constant reference that can be used
                // externally to get a consistent handle to the underlying mySolid topology.
                // In other words, faces[1] should always refer to the same topological Face
                // in mySolid.
                //
                // The value in this maps is the index to the vector returned by
                // mySolid->getFaces() . This value will change any time that mySolid changes.
                // Any change to mySolid _must_ be associated with a list of changed
                // topological Faces. This list will be used to update the values in these two
                // maps.
                std::map<FaceIndex, unsigned int> faces;

                // This map is used define each Edge in the solid. Similar to the `faces` map,
                // the key in `edges` is the constant reference that can be used to refer to
                // the underlying topology in mySolid.
                //
                // Unlike `faces`, `edges` does not refer directly to mySolid->getEdges().
                // Rather, `edges` stores a pair of integers which
                std::map<EdgeIndex, std::pair<FaceIndex, FaceIndex>> edges;
        };
}
#endif //SolidManager_Primitive_HEADER
