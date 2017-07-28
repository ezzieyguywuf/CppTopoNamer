#include <INamedSubShape.h>

INamedSubShape::INamedSubShape(const Shape myShape)
    : INamedShape(myShape)
{
}

INamedSubShape::INamedSubShape(const Shape myShape, const std::string myName)
    : INamedShape(myShape, myName)
{
}

INamedSubShape::~INamedSubShape(){}

unsigned int INamedSubShape::numParents() const{
    return this->myParentNames.size();
}
