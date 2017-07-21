#ifndef TOPONAMER_BOX
#define TOPONAMER_BOX

#include <Mock_TopoDS_Shape.h>
#include <Mock_TopoDS_Face.h>

#include <vector>

namespace mock{
    class Box : public TopoDS_Shape
    {
        public:
            Box(){};
            ~Box(){};

            std::vector<TopoDS_Face> Faces;
    };

}
#endif /* ifndef TOPONAMER_BOX */
