#include <TopoDS_Shape.hxx>
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

        private:
            TopoDS_Edge occEdge;
    };
}
