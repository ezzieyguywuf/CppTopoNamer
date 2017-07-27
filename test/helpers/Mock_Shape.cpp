#include <Shape.h>

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
