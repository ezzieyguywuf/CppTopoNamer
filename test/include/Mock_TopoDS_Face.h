#ifndef MOCK_TOPODS_FACE
#define MOCK_TOPODS_FACE

#include <Mock_TopoDS_Shape.h>
#include <Mock_TopoDS_Edge.h>
#include <vector>

namespace mock{
    class TopoDS_Face : public TopoDS_Shape{
        public:
            TopoDS_Face(unsigned int value);
            TopoDS_Face(unsigned int value, std::vector<TopoDS_Edge> Edges);
            ~TopoDS_Face(){};

            std::vector<TopoDS_Edge> Edges;
    };
}
#endif //MOCK_TOPODS_FACE
