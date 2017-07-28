#ifndef INamedShape_HEADER
#define INamedShape_HEADER

#include <Shape.h>
#include <memory>
#include <string>

class INamedShape
{
    public:
        INamedShape(const Shape myShape);
        INamedShape(const Shape myShape, const std::string myName);
        virtual ~INamedShape() = 0;

        std::string getName() const;
        Shape getShape() const;

    private:
        const Shape myShape;
        const std::string myName;
};
#endif // INamedSHape_HEADER
