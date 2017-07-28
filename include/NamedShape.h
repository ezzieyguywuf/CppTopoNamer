#ifndef NamedShape_HEADER
#define NamedShape_HEADER

#include <Shape.h>
#include <memory>
#include <string>

class NamedShape
{
    public:
        NamedShape(const Shape myShape);
        NamedShape(const Shape myShape, const std::string myName);
        ~NamedShape(){};

        //NamedShape& operator=(NamedShape& nshape);

        std::string getName() const;
        Shape getShape() const;
    private:
        const Shape myShape;
        const std::string myName;
};

#endif // NamedSHape_HEADER
