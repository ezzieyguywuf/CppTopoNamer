#ifndef ISHAPE_HEADER
#define ISHAPE_HEADER

#include <string>
#include <vector>


template <class TShape>
class IShape
{
    public:
        IShape(){};
        virtual ~IShape() {};

        // Returns true if `aShape` shares a location, orientation, and underlying
        // geometry with `this`
        virtual bool operator==(const TShape& aShape) const = 0;
        // Returns true if `aShape` shares a location as well as underlying geometry with
        // `this`. The two do not necessarily share an orientation
        virtual bool IsFlipped(const TShape& aShape) const = 0;
        //// Obtain a string representation of this Shape object
        //virtual std::string getRepr() const = 0;
};
#endif /* ifndef ISHAPE_HEADER */
