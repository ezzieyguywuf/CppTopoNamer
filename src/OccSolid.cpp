#include <OccTopology/OccSolid.h>

OccSolid::OccSolid(TopoDS_Solid aSolid)
    : mySolid(aSolid)
{

}
OccSolid::OccSolid(const OccSolid& aSolid){
}
OccSolid::OccSolid(OccSolid&& aSolid){
}
OccSolid OccSolid::operator=(const OccSolid& aSolid){
}
OccSolid OccSolid::operator=(OccSolid&& aSolid){
}
