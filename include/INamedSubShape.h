#ifndef INamedSubShape_HEADER
#define INamedSubShape_HEADER

#include <INamedShape.h>

class INamedSubShape : public INamedShape
{
    public:
        INamedSubShape(const Shape myShape);
        INamedSubShape(const Shape myShape, const std::string myName);
        ~INamedSubShape() override;

        // Implementation must determine how many parent names are needed in order to be
        // considered valid.
        virtual bool isValid() const = 0;
        // The number of parents names that we have.
        unsigned int numParents() const;
        // Add a parent. The implementation must determine if this parent is valid or not.
        // i.e. if `this` is an `Edge`, then a parent `Face` must contain `this`
        virtual void addParent(const INamedShape& parent) = 0;

    protected:
        std::vector<std::string> myParentNames;
};
#endif //INamedSubShape_HEADER
