//// This checks for whether we should use the real or mocked classes
//#ifdef UNIT_TESTING
//#include <Mock_TopExp_Explorer.hxx>
//#else
#include <TopExp_Explorer.hxx>
//#endif

#include <EdgeTracker.h>
#include <TopoDS.hxx>
#include <stdexcept>

namespace Trackers{
    EdgeTracker::EdgeTracker(TopoDS_Edge anEdge, std::string name)
        : BaseTracker(name)
    {
        this->occEdge = anEdge;
    }

    TopoDS_Edge EdgeTracker::getEdge() const
    {
        return this->occEdge;
    }

    void EdgeTracker::addFace(const FaceTracker& aFaceTracker)
    {
        TopoDS_Face aFace = aFaceTracker.getFace();
        if (this->checkEdges(aFace)){
        }
        else{
            std::string msg = "aFace must contain an Edge that IsSame to this->occEdge";
            throw std::invalid_argument(msg);
        }
    }

    bool EdgeTracker::isValid() const
    {
        if (this->myFaceNames.size() == 2){
            return true;
        }
        return false;
    }

//---------------------------------------------------------------------------
//         private methods
//---------------------------------------------------------------------------
    bool EdgeTracker::checkEdges(const TopoDS_Face& aFace) const
    {
        TopExp_Explorer Edges(aFace, TopAbs_EDGE);
        for(;Edges.More();Edges.Next()){
            const TopoDS_Edge anEdge = TopoDS::Edge(Edges.Current());
            if (anEdge.IsSame(this->occEdge)){
                return true;
            }
        }
        return false;
    }
}
