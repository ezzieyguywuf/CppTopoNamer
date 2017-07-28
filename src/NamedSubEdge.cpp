#include <NamedSubEdge.h>

NamedSubEdge::NamedSubEdge(const Shape aShape)
    : INamedSubShape(aShape)
{
}

NamedSubEdge::NamedSubEdge(const Shape aShape, const std::string aName)
    : INamedSubShape(aShape, aName)
{
}

bool NamedSubEdge::isValid() const
{
    if (myParentNames.size() == 2){
        return true;
    }
    return false;
}

void NamedSubEdge::addParent(const INamedShape& parent)
{
    this->myParentNames.push_back((&parent)->getName());
}
