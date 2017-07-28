#ifndef NamedSubEdge_HEADER
#define NamedSubEdge_HEADER

#include <INamedSubShape.h>

class NamedSubEdge : public INamedSubShape
{
    public:
        NamedSubEdge(const Shape myShape);
        NamedSubEdge(const Shape myShape, const std::string myName);
        ~NamedSubEdge(){};

        bool isValid() const override;
        void addParent(const INamedShape& parent) override;
};

#endif //NamedSubEdge_HEADER
