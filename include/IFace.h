#ifndef IFACE_HEADER
#define IFACE_HEADER

#include <IShape.h>
#include <IEdge.h>
#include <memory>

class IFace : IShape
{
    public:
        std::vector<std::unique_pointer<IShape>> getSubShapes() const = 0;
        // convenience method, could use `getSubShapes`
        std::vector<std::unique_pointer<IEdge>> getEdges() const = 0;
};
#endif /* ifndef IFACE_HEADER */
