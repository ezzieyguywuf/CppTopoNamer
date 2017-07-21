#ifndef MOCK_TOPODS_EDGE
#define MOCK_TOPODS_EDGE
#include <Mock_TopoDS_Shape.h>
#include <TopoDS_Edge.hxx>

namespace mock{
    class TopoDS_Edge : public TopoDS_Shape, public ::TopoDS_Edge{
        public:
            TopoDS_Edge(unsigned int value);
            ~TopoDS_Edge(){};
    };
}
#endif //MOCK_TOPODS_EDGE
