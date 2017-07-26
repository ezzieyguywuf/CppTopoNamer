#ifndef MOCK_FACE_HEADER
#define MOCK_FACE_HEADER

#include <Mock_Edge.h>
#include <Mock_Shape.h>
#include <memory>

namespace mock{
class Face : public Shape
    {
        public:
            Face(int value, std::vector<Edge> edges);
            std::vector<std::unique_ptr<IShape>> getSubShapes() const override {};
            std::vector<Edge> getEdges() const;
        private:
            std::vector<Edge> myEdges;
    };
};
#endif /* ifndef MOCK_FACE_HEADER */
