#ifndef MOCK_EDGE_HEADER
#define MOCK_EDGE_HEADER

#include <Mock_Shape.h>

namespace mock{
    class Edge : public Shape
    {
        public:
            Edge(int value);
            std::vector<std::unique_ptr<IShape>> getSubShapes() const override{};
    };
};
#endif /* ifndef MOCK_EDGE_HEADER */
