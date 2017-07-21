#ifndef TOPONAMER_FACE_TRACKER
#define TOPONAMER_FACE_TRACKER

#include <BaseTracker.h>
#include <TopoDS_Face.hxx>

namespace Trackers{
    class FaceTracker : public BaseTracker{
        public:
            FaceTracker(TopoDS_Face anFace, std::string name);
            ~FaceTracker(){};
            // A convenience function. Could use getOccObject()
            TopoDS_Face getFace() const;

        private:
            TopoDS_Face myFace;
    };
}
#endif /* ifndef TOPONAMER_FACE_TRACKER */
