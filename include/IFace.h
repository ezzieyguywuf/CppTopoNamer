#ifndef IFACE_HEADER
#define IFACE_HEADER

#include <IShape.h>
#include <IEdge.h>
#include <memory>

class IFace : IShape
{
    public:
        virtual ~IFace() = 0;
        std::vector<std::unique_ptr<IShape>> getSubShapes() const = 0;
        // convenience method, could use `getSubShapes`
        std::vector<std::unique_ptr<IEdge>> getEdges() const = 0;
};
IFace::~IFace(){}
#endif /* ifndef IFACE_HEADER */
