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
        ~INamedShape(){};

        std::string getName() const;
        Shape getShape() const;

        // Implementation must determine how many parent names are needed in order to be
        // considered valid.
        virtual bool isValid() const = 0;
    private:
        const Shape myShape;
        const std::string myName;

    protected:
        const std::vector<std::string> myParentNames;
};

#endif // INamedSHape_HEADER
