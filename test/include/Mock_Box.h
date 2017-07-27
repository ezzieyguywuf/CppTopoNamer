#ifndef TOPONAMER_BOX
#define TOPONAMER_BOX

#include <Mock_Face.h>
#include <Mock_Shape.h>
#include <IShapeWithSubs.h>

#include <vector>

namespace mock{
    class Box : public Shape, public IShapeWithSubs<Shape, Face>
    {
        public:
            Box(std::vector<Face> faces);
            ~Box(){};

            using Shape::operator=;
            using Shape::IsFlipped;

            std::vector<Face> myFaces;
    };

}
#endif /* ifndef TOPONAMER_BOX */
