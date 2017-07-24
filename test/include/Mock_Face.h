#ifndef MOCK_FACE_HEADER
#define MOCK_FACE_HEADER

#include <IFace.h>
#include <Mock_Edge.h>
#include <Mock_Shape.h.>
#include <memory>

namespace mock{
class Face : public Mock_Shape, public ::IFace
    {
        public:
            Face(int value, std::vector<std::unique_pointer<Edge>> edges);
            std::vector<std::unique_pointer<Edge>> getEdges() const;
        private:
            std::vector<std::unique_pointer<Edge>> myEdges;
    };
};
#endif /* ifndef MOCK_FACE_HEADER */
