#include <OccObjectTrackers.h>

namespace Trackers{
    OccObjectTracker::OccObjectTracker(TopoDS_Shape trackedObject, std::string name){
        this->occObject = trackedObject;
        this->name = name;
    }

    TopoDS_Shape OccObjectTracker::getOCCObject() const{
        return this->occObject;
    }
}
