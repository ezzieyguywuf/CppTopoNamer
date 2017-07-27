#ifndef MOCK_FACE_HEADER
#define MOCK_FACE_HEADER

#include <Mock_Edge.h>
#include <Mock_Shape.h>
#include <IShapeWithSubs.h>
#include <memory>

namespace mock{
class Face : public Shape, public IShapeWithSubs<Shape, Edge>
    {
        public:
            Face(int value, std::vector<Edge> edges);

            using Shape::operator=;
            using Shape::IsFlipped;

            std::vector<Edge> myEdges;
    };
};
#endif /* ifndef MOCK_FACE_HEADER */
