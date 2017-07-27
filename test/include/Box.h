#ifndef TOPONAMER_BOX
#define TOPONAMER_BOX

#include <Face.h>
#include <Shape.h>
#include <IShapeWithSubs.h>

#include <vector>

class Box : public Shape, public IShapeWithSubs<Shape, Face>
{
    public:
        Box(std::vector<Face> faces);
        ~Box(){};

        using Shape::operator=;
        using Shape::IsFlipped;

        std::vector<Face> myFaces;
};
#endif /* ifndef TOPONAMER_BOX */
