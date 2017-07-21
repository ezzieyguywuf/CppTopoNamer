#ifndef TOPONAMER_BASE_TRACKER
#define TOPONAMER_BASE_TRACKER

#include <string>

class BaseTracker{
    // TODO: maybe delete this class, it is a holdover from my python implementation
    public:
        BaseTracker(std::string name);
        ~BaseTracker(){};
        std::string getName() const;

    private:

        std::string name;
};
#endif /* ifndef TOPONAMER_BASE_TRACKER */
