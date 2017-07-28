#include <Shape.h>

const std::string Shape::REPR = "Shape";
Shape::Shape(int value) 
    : value(value)
{}

bool Shape::operator==(const Shape& aShape) const
{
    return this->value == aShape.getValue();
}

bool Shape::IsFlipped(const Shape& aShape) const
{
    return *this == aShape;
}

int Shape::getValue() const
{
    return this->value;
}

//std::ostream& Shape::operator<< (std::ostream& stream, const Shape& shape){
    //stream << "<" << shape.REPR << " object at address=" << this <<", value=" << shape.value << std::endl;
    //return stream;
//}
