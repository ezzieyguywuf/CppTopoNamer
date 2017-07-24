#ifndef TOPONAMER_FACE_TRACKER
#define TOPONAMER_FACE_TRACKER

#include <BaseTracker.h>
#include <IFace.h>
#include <memory>

namespace Trackers{
    class FaceTracker : public BaseTracker{
        public:
            FaceTracker(std::unique_pointer<IFace> anFace, std::string name);
            ~FaceTracker(){};
    };
}
#endif /* ifndef TOPONAMER_FACE_TRACKER */
