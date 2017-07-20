#include <TopoDS_Shape.hxx>
#include <string>

namespace Trackers{
    class OccObjectTracker{
        public:
            OccObjectTracker(TopoDS_Shape trackedObject, std::string name);
            ~OccObjectTracker(){};

            TopoDS_Shape getOCCObject() const;

        private:
            TopoDS_Shape occObject;
            std::string name;
    };
}
