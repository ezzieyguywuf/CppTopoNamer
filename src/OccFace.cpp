#include <OccTopology/OccFace.h>
#include <OccTopology/OccEdge.h>

#include <TopoDS.hxx>
#include <TopExp_Explorer.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Edge.hxx>

using std::unique_ptr;

OccFace::OccFace(TopoDS_Face aFace)
{
    myFace = aFace;
    for(TopExp_Explorer exp(myFace, TopAbs_EDGE); exp.More(); exp.Next())
    {
        TopoDS_Edge currentEdge = TopoDS::Edge(exp.Current());
        myEdges.push_back(std::move(unique_ptr<IEdge>(new OccEdge(currentEdge))));
    }
}

OccFace::OccFace(const OccFace& aFace)
    : myFace(aFace.myFace)
{
    for (const auto& edge : aFace.myEdges){
        const OccEdge& occEdge = static_cast<OccEdge&>(*edge.get());
        myEdges.push_back(std::move(unique_ptr<IEdge>(new OccEdge(occEdge.getEdge()))));
    }
}

OccFace::OccFace(OccFace&& aFace)
    : myFace(aFace.myFace), myEdges(std::move(aFace.myEdges))
{
    aFace.myFace.Nullify();
}

OccFace OccFace::operator=(const OccFace& aFace)
{
    myFace = aFace.myFace;
    myEdges.clear();
    for (const auto& edge: aFace.myEdges)
    {
        const OccEdge& occEdge = static_cast<const OccEdge&>(*edge.get());
        myEdges.push_back(std::move(unique_ptr<OccEdge>(new OccEdge(occEdge.getEdge()))));
    }
    return *this;
}

OccFace OccFace::operator=(OccFace&& aFace)
{
    myFace = aFace.myFace;
    myEdges.clear();
    myEdges = std::move(aFace.myEdges);
    aFace.myFace.Nullify();
    return *this;
}

bool OccFace::operator==(const OccFace& aFace) const 
{
    return myFace.IsEqual(aFace.myFace);
}

bool OccFace::isFlipped(const OccFace& aFace) const 
{
    return myFace.IsSame(aFace.myFace);
}

const vector<unique_ptr<IEdge>>& OccFace::getEdgeVector() const 
{
    return myEdges;
}

// ---------------- PRIVATE METHODS ----------------
const TopoDS_Face& OccFace::getFace() const
{
    return this->myFace;
}
