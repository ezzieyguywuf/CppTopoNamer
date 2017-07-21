#include <FaceTracker.h>

namespace Trackers{
    FaceTracker::FaceTracker(TopoDS_Face aFace, std::string aName)
        : BaseTracker(aName)
    {
        this->myFace = aFace;
    }

    TopoDS_Face FaceTracker::getFace() const
    {
        return this->myFace;
    }
}
