#include <OccTopology/OccEdge.h>

OccEdge::OccEdge(TopoDS_Edge aEdge)
{
    myEdge = aEdge;
}

OccEdge::OccEdge(const OccEdge& aEdge)
{
    myEdge = aEdge.myEdge;
}

OccEdge::OccEdge(OccEdge&& aEdge)
{
    if (this !=  &aEdge){
        myEdge.Nullify();
        myEdge = aEdge.myEdge;
        aEdge.myEdge.Nullify();
    }
}

OccEdge OccEdge::operator=(const OccEdge& aEdge)
{
    myEdge = aEdge.myEdge;
    return *this;
}

OccEdge OccEdge::operator=(OccEdge&& aEdge)
{
    myEdge.Nullify();
    myEdge = aEdge.myEdge;
    aEdge.myEdge.Nullify();
    return *this;
}

bool OccEdge::operator==(const OccEdge& aEdge) const
{
    return myEdge.IsEqual(aEdge.myEdge);
}

bool OccEdge::isFlipped(const OccEdge& aEdge) const
{
    return myEdge.IsSame(aEdge.myEdge);
}

void OccEdge::updateEdge(TopoDS_Edge aEdge)
{
    myEdge = aEdge;
}

const TopoDS_Edge& OccEdge::getEdge() const
{
    return myEdge;
}

