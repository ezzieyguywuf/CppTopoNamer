#ifndef TOPONAMER_EDGE_TRACKER
#define TOPONAMER_EDGE_TRACKER

#include <BaseTracker.h>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>

namespace Trackers{
    class EdgeTracker : public BaseTracker{
        public:
            EdgeTracker(TopoDS_Edge anEdge, std::string name);
            ~EdgeTracker(){};
            // A convenience function. Could use getOccObject()
            TopoDS_Edge getEdge() const;
            void addFace(TopoDS_Face aFace);

        private:
            bool checkEdges(const TopoDS_Face& aFace) const;
            TopoDS_Edge occEdge;
    };
}

#endif /* ifndef TOPONAMER_EDGE_TRACKER */
