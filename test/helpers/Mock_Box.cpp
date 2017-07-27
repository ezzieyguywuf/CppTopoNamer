#include <Mock_Box.h>

using namespace mock;

Box::Box(std::vector<Face> faces)
    : Shape(-1), myFaces(faces), IShapeWithSubs(faces)
{}
