#include <NamedSubEdge.h>
#include <Base/Exception.h>

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
    if (myParentNames.size() < 2){
        this->myParentNames.push_back((&parent)->getName());
    }
    else{
        THROWM(Base::RuntimeError, "Too many parent Faces were added: an Edge can only be made up of up to two Faces.");
    }
}
