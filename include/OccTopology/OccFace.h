#ifndef OccFace_HEADER
#define OccFace_HEADER

#include <Topology/IFace.h>
#include <Topology/IEdge.h>

#include <TopoDS_Face.hxx>

#include <vector>
#include <memory> // for unique_ptr, std::move, etc...

using std::vector;
using std::unique_ptr;

class OccFace : public IFace_<OccFace>
{
    public:
        OccFace(TopoDS_Face aFace);
        OccFace(const OccFace& aFace);
        OccFace(OccFace&& aFace);
        OccFace operator=(const OccFace& aFace);
        OccFace operator=(OccFace&& aFace);
        OccFace(){};

        // overrides from IFace_
        bool operator==(const OccFace& aFace) const override;
        bool isFlipped(const OccFace& aFace) const override;
        const vector<unique_ptr<IEdge>>& getEdgeVector() const override;

        // unique to OccFace
        //void updateFace(TopoDS_Face aFace);

    private:
        TopoDS_Face myFace;
        vector<unique_ptr<IEdge>> myEdges;
};

#endif //OccFace_HEADER
