#include<Mock_TopoDS_Shape.h>

using namespace mock;

TopoDS_Shape::TopoDS_Shape(unsigned int value)
{
    this->value = value;
}

bool TopoDS_Shape::IsEqual(const TopoDS_Shape& check) const{
    return this->getValue() == check.getValue();
}
bool TopoDS_Shape::IsSame(const TopoDS_Shape& check) const{
    return this->IsEqual(check);
}

unsigned int TopoDS_Shape::getValue() const{
    return this->value;
}

