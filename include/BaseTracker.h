#ifndef TOPONAMER_BASE_TRACKER
#define TOPONAMER_BASE_TRACKER

#include <string>
#include <IShape.h>
#include <memory>

class BaseTracker{
    // TODO: maybe delete this class, it is a holdover from my python implementation
    public:
        BaseTracker(std::unique_pointer<IShape> aShape, std::string name);
        virtual ~BaseTracker() = 0;
        bool operator==(const BaseTracker& toCheck) const;
        std::string getName() const;

    private:

        std::string name;
        std::unique_pointer<IShape> myShape;
};
#endif /* ifndef TOPONAMER_BASE_TRACKER */
