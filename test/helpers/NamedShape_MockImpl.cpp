#include <NamedShape_MockImpl.h>

NamedShape::NamedShape(const Shape aShape)
    : INamedShape(aShape)
{
}

NamedShape::NamedShape(const Shape aShape, const std::string aName)
    : INamedShape(aShape, aName)
{
}
        
bool NamedShape::isValid() const
{
    return false;
}

