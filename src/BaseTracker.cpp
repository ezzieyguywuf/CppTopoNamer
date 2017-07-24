#include <BaseTracker.h>

BaseTracker::BaseTracker(std::unique_pointer<IShape> aShape, std::string name)
    : myShape(aShape), name(name)
{
}

bool BaseTracker::operator== (const BaseTracker& toCheck) const
{
    return this->myShape == toCheck
}

std::string BaseTracker::getName() const
{
    return this->name;
}
