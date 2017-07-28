#ifndef NamedShape_HEADER
#define NamedShape_HEADER

#include <INamedShape.h>

class NamedShape : public INamedShape
{
    public:
        NamedShape(const Shape aShape);
        NamedShape(const Shape aShape, const std::string aName);
        ~NamedShape(){};
        bool isValid() const override;
};

#endif //NamedShape_HEADER
