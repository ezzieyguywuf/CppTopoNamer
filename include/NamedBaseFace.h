#ifndef NamedBaseFace_HEADER
#define NamedBaseFace_HEADER

#include <INamedShape.h>

class NamedBaseFace : public INamedShape
{
    public:
        NamedBaseFace(const Shape aShape);
        NamedBaseFace(const Shape aShape, const std::string aName);
        ~NamedBaseFace(){};
};

#endif //NamedBaseFace_HEADER
