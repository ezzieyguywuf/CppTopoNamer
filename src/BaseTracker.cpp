#include <BaseTracker.h>

BaseTracker::BaseTracker(std::string name)
{
    this->name = name;
}

std::string BaseTracker::getName() const
{
    return this->name;
}
