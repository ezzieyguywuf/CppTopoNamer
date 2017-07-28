#include <NamedShape.h>
#include <memory>

NamedShape::NamedShape(const Shape myShape)
    : myShape(myShape)
{
}

NamedShape::NamedShape(const Shape oldShape, const std::string myName)
    : myShape(oldShape), myName(myName)
{
}

std::string NamedShape::getName() const{
    return this->myName;
}

Shape NamedShape::getShape() const{
    return this->myShape;
}

//NamedShape& NamedShape::operator=(NamedShape& nshape){
    //this->myShape = nshape.myShape;
    //this->myName  = nshape.myName;
//}
