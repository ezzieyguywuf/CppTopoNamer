#include <NamedEdge.h>

NamedEdge::NamedEdge(const Shape aShape)
    : INamedShape(aShape)
{
}

NamedEdge::NamedEdge(const Shape aShape, const std::string aName)
    : INamedShape(aShape, aName)
{
}

bool NamedEdge::isValid() const
{
    if (myParentNames.size() == 2){
        return true;
    }
    return false;
}
