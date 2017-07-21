#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <string>

namespace Trackers{
    class OccObjectTracker{
        // TODO: maybe delete this class, it is a holdover from my python implementation
        public:
            OccObjectTracker(std::string name);
            ~OccObjectTracker(){};

            std::string getName() const;

        private:
            std::string name;
    };

    class EdgeTracker : public OccObjectTracker{
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
