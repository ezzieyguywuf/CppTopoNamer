#include <Box.h>

Box::Box(std::vector<Face> faces)
    : Shape(-1), myFaces(faces), IShapeWithSubs(faces)
{}
