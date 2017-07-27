#ifndef MOCK_FACE_HEADER
#define MOCK_FACE_HEADER

#include <Edge.h>
#include <Shape.h>
#include <IShapeWithSubs.h>
#include <memory>

class Face : public Shape, public IShapeWithSubs<Shape, Edge>
{
    public:
        Face(int value, std::vector<Edge> edges);

        using Shape::operator=;
        using Shape::IsFlipped;

        std::vector<Edge> myEdges;
};
#endif /* ifndef MOCK_FACE_HEADER */
