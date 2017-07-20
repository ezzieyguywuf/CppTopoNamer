#include <OccObjectTrackers.h>

namespace Trackers{
    OccObjectTracker::OccObjectTracker(std::string name)
    {
        this->name = name;
    }

    std::string OccObjectTracker::getName() const
    {
        return this->name;
    }

    EdgeTracker::EdgeTracker(TopoDS_Edge anEdge, std::string name)
        : OccObjectTracker(name)
    {
        this->occEdge = anEdge;
    }

    TopoDS_Edge EdgeTracker::getEdge() const
    {
        return this->occEdge;
    }
}
