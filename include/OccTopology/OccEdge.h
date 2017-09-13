#ifndef OccEdge_HEADER
#define OccEdge_HEADER

#include <Topology/IFace.h>
#include <Topology/IEdge.h>

#include <TopoDS_Edge.hxx>

#include <vector>
#include <memory> // for unique_ptr, std::move, etc...

using std::vector;
using std::unique_ptr;

class OccEdge : public IEdge_<OccEdge>
{
    public:
        OccEdge(TopoDS_Edge aEdge);
        OccEdge(const OccEdge& aEdge);
        OccEdge(OccEdge&& aEdge);
        OccEdge operator=(const OccEdge& aEdge);
        OccEdge operator=(OccEdge&& aEdge);
        OccEdge(){};

        // overrides from IEdge_
        bool operator==(const OccEdge& aEdge) const override;
        bool isFlipped(const OccEdge& aEdge) const override;

        // unique to OccEdge
        void updateEdge(TopoDS_Edge aEdge);
        const TopoDS_Edge& getEdge() const;

    private:
        TopoDS_Edge myEdge;
};

#endif //OccEdge_HEADER
