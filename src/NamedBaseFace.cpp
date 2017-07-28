#include<NamedBaseFace.h>

NamedBaseFace::NamedBaseFace(const Shape aShape)
    : INamedShape(aShape)
{
}

NamedBaseFace::NamedBaseFace(const Shape aShape, const std::string aName)
    : INamedShape(aShape, aName)
{
}
