#include <Mock_Shape.h>

using mock::Shape;

Shape::Shape(int value) 
    : value(value)
{}

bool Shape::operator==(std::unique_pointer<Shape> aShape) const
{
    return this->value == aShape->getValue();
}

bool Shape::IsFlipped(std::unique_pointer<Shape> aShape) const
{
    return this == aShape;
}

int Shape::getValue() const
{
    return this->value;
}
