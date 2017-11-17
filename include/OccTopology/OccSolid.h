#ifndef OccSolid_HEADER
#define OccSolid_HEADER

#include <Topology/ISolid.h>
#include <Topology/IFace.h>
#include <Topology/IEdge.h>

#include <TopoDS_Solid.hxx>

#include <vector>
#include <memory> // for unique_ptr, std::move, etc...

using std::vector;
using std::unique_ptr;

class OccSolid : public ISolid
{
    public:
        OccSolid(TopoDS_Solid aSolid);
        OccSolid(const OccSolid& aSolid);
        OccSolid(OccSolid&& aSolid);
        OccSolid operator=(const OccSolid& aSolid);
        OccSolid operator=(OccSolid&& aSolid);
        OccSolid(){};

        const vector<unique_ptr<IFace>>& getFaceVector() const;
        const vector<unique_ptr<IEdge>>& getEdgeVector() const;

    private:
        TopoDS_Solid mySolid;
        // Note: this method is a good candidate for opitimization. It currently loops
        // through every myEdges to check for duplicates, there must be more efficient
        // ways to do this.
        void updateMyEdges();
        vector<unique_ptr<IFace>> myFaces;
        vector<unique_ptr<IEdge>> myEdges;
};

#endif //OccSolid_HEADER
