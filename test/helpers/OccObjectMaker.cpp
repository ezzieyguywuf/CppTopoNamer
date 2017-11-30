#include <OccObjectMaker.h>

#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS.hxx>

#include <OccTopology/OccSolid.h>

std::unique_ptr<ISolid> OccObjectMaker::makeBox()
{
    TopoDS_Shape boxShape = BRepPrimAPI_MakeBox(10., 10., 10.);
    TopoDS_Solid boxSolid = TopoDS::Solid(boxShape);

    return std::unique_ptr<ISolid>(new OccSolid(boxSolid));
}

std::unique_ptr<ISolid> OccObjectMaker::makeCyl()
{
    TopoDS_Shape cylShape = BRepPrimAPI_MakeCylinder(2., 10.);
    TopoDS_Solid cylSolid = TopoDS::Solid(cylShape);

    return std::unique_ptr<ISolid>(new OccSolid(cylSolid));
}
