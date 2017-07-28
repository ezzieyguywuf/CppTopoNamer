#ifndef NamedEdge_HEADER
#define NamedEdge_HEADER

#include <INamedShape.h>

class NamedEdge : INamedShape
{
    public:
        NamedEdge(const Shape myShape);
        NamedEdge(const Shape myShape, const std::string myName);
        ~NamedEdge(){};

        bool isValid() const override;
};

#endif //NamedEdge_HEADER
