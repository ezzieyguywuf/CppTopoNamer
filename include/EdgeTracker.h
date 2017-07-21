#ifndef TOPONAMER_EDGE_TRACKER
#define TOPONAMER_EDGE_TRACKER

#include <BaseTracker.h>
#include <FaceTracker.h>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <vector>

namespace Trackers{
    class EdgeTracker : public BaseTracker{
        public:
            EdgeTracker(TopoDS_Edge anEdge, std::string name);
            ~EdgeTracker(){};
            // A convenience function. Could use getOccObject()
            TopoDS_Edge getEdge() const;
            // Adds `aFaceTracker`s `faceName` to the list of Faces that share this edge.
            //
            // throws: std::invalid_argument if `aFaceTracker`s `TopoDS_Face` does not
            // contain `this->occEdge`
            void addFace(const FaceTracker& aFaceTracker);
            // Returns `true` if there are two `TopoDS_Face`s that share this edge
            bool isValid() const;

        private:
            bool checkEdges(const TopoDS_Face& aFace) const;
            TopoDS_Edge occEdge;
            std::vector<std::string> myFaceNames;
    };
}

#endif /* ifndef TOPONAMER_EDGE_TRACKER */
