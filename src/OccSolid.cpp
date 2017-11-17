#include <OccTopology/OccSolid.h>
#include <OccTopology/OccFace.h>
#include <OccTopology/OccEdge.h>
#include <algorithm> // for std::find

#include <TopoDS.hxx>
#include <TopExp_Explorer.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Face.hxx>

OccSolid::OccSolid(TopoDS_Solid aSolid)
    : mySolid(aSolid)
{
    for (TopExp_Explorer exp(mySolid, TopAbs_FACE); exp.More(); exp.Next())
    {
        TopoDS_Face currentFace = TopoDS::Face(exp.Current());
        myFaces.push_back(std::move(std::unique_ptr<IFace>(new OccFace(currentFace))));
    }
    this->updateMyEdges();
}
OccSolid::OccSolid(const OccSolid& aSolid){
}
OccSolid::OccSolid(OccSolid&& aSolid){
}
OccSolid OccSolid::operator=(const OccSolid& aSolid){
}
OccSolid OccSolid::operator=(OccSolid&& aSolid){
}

// --------------- PRIVATE METHODS ----------------
void OccSolid::updateMyEdges()
{
    for (const auto& aFace : myFaces)
    {
        for (const auto& anEdge : aFace->getEdges())
        {
            if (std::find(myEdges.begin(), myEdges.end(), anEdge) == myEdges.end())
            {
                // if true, then anEdge is not in the vector
                const OccEdge* anOccEdge = static_cast<const OccEdge*>(anEdge.get());
                myEdges.push_back(std::move(std::unique_ptr<IEdge>(new OccEdge(*anOccEdge))));
                delete(anOccEdge);
            }
        }
    }
}
