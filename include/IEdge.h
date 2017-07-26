#ifndef IEDGE_HEADER
#define IEDGE_HEADER value

#include <IShape.h>
class IEdge : IShape
{
    public:
        virtual ~IEdge() = 0;
};
IEdge::~IEdge(){}
#endif /* ifndef IEDGE_HEADER */
