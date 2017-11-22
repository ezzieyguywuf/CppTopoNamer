#include <OccTopology/OccSolid.h>
#include <OccTopology/OccFace.h>
#include <OccTopology/OccEdge.h>
#include <algorithm> // for std::find

#include <TopoDS.hxx>
#include <TopExp_Explorer.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Face.hxx>

OccSolid::OccSolid(TopoDS_Solid aSolid)
    : myShape(aSolid)
{
    this->initialize();
}

OccSolid::OccSolid(TopoDS_CompSolid aSolid)
    : myShape(aSolid)
{
    this->initialize();
}

OccSolid::OccSolid(TopoDS_Compound aSolid)
    : myShape(aSolid)
{
    this->initialize();
}

OccSolid::OccSolid(const OccSolid& aSolid)
    : myShape(aSolid.myShape)
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
    : myShape(aSolid.myShape), myFaces(std::move(aSolid.myFaces)), myEdges(std::move(aSolid.myEdges))
{
    aSolid.myShape.Nullify();
    aSolid.myFaces.clear();
    aSolid.myEdges.clear();
}
OccSolid OccSolid::operator=(const OccSolid& aSolid){
    myShape = aSolid.myShape;
    myFaces.clear();
    myEdges.clear();
    for (const auto& aFace : aSolid.myFaces)
    {
        const OccFace& occFace = static_cast<const OccFace&>(*aFace.get());
        myFaces.push_back(std::move(std::unique_ptr<OccFace>(new OccFace(occFace))));
    }
    for (const auto& anEdge: aSolid.myEdges)
    {
        const OccEdge& occEdge = static_cast<const OccEdge&>(*anEdge.get());
        myEdges.push_back(std::move(unique_ptr<OccEdge>(new OccEdge(occEdge.getEdge()))));
    }
}
OccSolid OccSolid::operator=(OccSolid&& aSolid){
    if (this != &aSolid){
        myShape.Nullify();
        myShape = aSolid.myShape;
        myFaces.clear();
        myFaces = std::move(aSolid.myFaces);
        myEdges.clear();
        myEdges = std::move(aSolid.myEdges);
        aSolid.myShape.Nullify();
        aSolid.myFaces.clear();
        aSolid.myEdges.clear();
    }
    return *this;
}

bool OccSolid::isValid() const
{
    if (myShape.IsNull()){
        return false;
    }
    return true;
}

const vector<unique_ptr<IFace>>& OccSolid::getFaceVector() const
{
    return this->myFaces;
}
const vector<unique_ptr<IEdge>>& OccSolid::getEdgeVector() const
{
    return this->myEdges;
}

const TopoDS_Shape& OccSolid::getShape() const
{
    return this->myShape;
}

// --------------- PRIVATE METHODS ----------------
void OccSolid::updateMyEdges()
{
    bool found;
    for (const std::unique_ptr<IFace>& aFace : myFaces)
    {
        for (const std::unique_ptr<IEdge>& anEdge : aFace->getEdges())
        {
            found = false;
            for (const std::unique_ptr<IEdge>& checkEdge : myEdges)
            {
                if (checkEdge->isFlipped(*anEdge))
                {
                    found = true;
                    break;
                }
            }
            if (not found)
            {
                const OccEdge* anOccEdge = static_cast<const OccEdge*>(anEdge.get());
                myEdges.push_back(std::move(std::unique_ptr<IEdge>(new OccEdge(*anOccEdge))));
            }
        }
    }
}

void OccSolid::initialize()
{
    for (TopExp_Explorer exp(this->myShape, TopAbs_FACE); exp.More(); exp.Next())
    {
        TopoDS_Face currentFace = TopoDS::Face(exp.Current());
        myFaces.push_back(std::move(std::unique_ptr<IFace>(new OccFace(currentFace))));
    }
    this->updateMyEdges();
}
