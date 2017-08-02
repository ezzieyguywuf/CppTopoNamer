#include <Mock_Face.h>
#include <Mock_Edge.h>

using Mock::Face;
using Mock::Edge;
using std::unique_ptr;
using std::vector;

Face::Face (int value, const vector<unsigned int> indices)
    : myIndices(indices), myValue(value)
{}

bool Face::operator==(const Face& aFace) const
{
    return this->myValue == aFace.getValue();
}

bool Face::isFlipped(const Face& aFace) const
{
    return (*this) == aFace;
}

vector<unsigned int> Face::myEdgeIndices() const
{
    return this->myIndices;
}

int Face::getValue() const{
    return myValue;
}
