#include <INamedShape.h>
#include <memory>

INamedShape::INamedShape(const Shape myShape)
    : myShape(myShape)
{
}

INamedShape::INamedShape(const Shape oldShape, const std::string myName)
    : myShape(oldShape), myName(myName)
{
}

std::string INamedShape::getName() const{
    return this->myName;
}

Shape INamedShape::getShape() const{
    return this->myShape;
}

//INamedShape& INamedShape::operator=(INamedShape& nshape){
    //this->myShape = nshape.myShape;
    //this->myName  = nshape.myName;
//}
