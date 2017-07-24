#ifndef MOCK_EDGE_HEADER
#define MOCK_EDGE_HEADER

#include <IEdge.h>
#include <Mock_Shape.h>

namespace mock{
    class Edge : public Mock_Shape , ::IEdge
    {
        Edge(int value);
        ~Edge(){};
    };
};
#endif /* ifndef MOCK_EDGE_HEADER */
