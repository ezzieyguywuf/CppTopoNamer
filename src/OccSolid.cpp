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
OccSolid::OccSolid(const OccSolid& aSolid)
    : mySolid(aSolid.mySolid)
{
    for (const auto& edge : aSolid.myEdges){
        const OccEdge& occEdge = static_cast<OccEdge&>(*edge.get());
        myEdges.push_back(std::move(unique_ptr<IEdge>(new OccEdge(occEdge.getEdge()))));
    }

    for (const auto& face : aSolid.myFaces){
        const OccFace& occFace = static_cast<OccFace&>(*face.get());
        myFaces.push_back(std::move(unique_ptr<IFace>(new OccFace(occFace.getFace()))));
    }
}
OccSolid::OccSolid(OccSolid&& aSolid)
    : mySolid(aSolid.mySolid), myFaces(std::move(aSolid.myFaces)), myEdges(std::move(aSolid.myEdges))
{
    aSolid.mySolid.Nullify();
    aSolid.myFaces.clear();
    aSolid.myEdges.clear();
}
OccSolid OccSolid::operator=(const OccSolid& aSolid){
}
OccSolid OccSolid::operator=(OccSolid&& aSolid){
    if (this != &aSolid){
        mySolid.Nullify();
        mySolid = aSolid.mySolid;
        myFaces.clear();
        myFaces = std::move(aSolid.myFaces);
        myEdges.clear();
        myEdges = std::move(aSolid.myEdges);
        aSolid.mySolid.Nullify();
        aSolid.myFaces.clear();
        aSolid.myEdges.clear();
    }
    return *this;
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
