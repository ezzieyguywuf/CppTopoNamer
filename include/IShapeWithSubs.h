#ifndef IShapeWithSubs_HEADER
#define IShapeWithSubs_HEADER

#include <IShape.h>
#include <vector>

template <class TShape, class TSubShape>
class IShapeWithSubs : virtual public IShape<TShape>
{
    public:
        IShapeWithSubs(std::vector<TSubShape> shapes) : mySubs(shapes){};
        virtual std::vector<TSubShape> getSubShapes() const
        {
            return this->mySubs;
        };

    private:
        std::vector<TSubShape> mySubs;
};

#endif // IShapeWithSubs_HEADER
