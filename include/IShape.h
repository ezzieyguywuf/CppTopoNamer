#ifndef ISHAPE_HEADER
#define ISHAPE_HEADER

#include <string>
#include <memory>
#include <vector>

class IShape
{
    public:
        IShape(){};
        virtual ~IShape() {};

        // Returns true if `aShape` shares a location, orientation, and underlying
        // geometry with `this`
        virtual bool operator==(const IShape& aShape) const = 0;
        // Returns true if `aShape` shares a location as well as underlying geometry with
        // `this`. The two do not necessarily share an orientation
        virtual bool IsFlipped(const IShape& aShape) const = 0;
        virtual std::vector<std::unique_ptr<IShape>> getSubShapes() const = 0;
};
#endif /* ifndef ISHAPE_HEADER */
