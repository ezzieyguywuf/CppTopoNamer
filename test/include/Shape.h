#ifndef Shape_Impl_Header
#define Shape_Impl_Header


#include <IShape.h>

class Shape : virtual public IShape<Shape>
{
    public:
        Shape(int value);

        bool operator==(const Shape& aShape) const override;
        bool IsFlipped(const Shape& aShape) const override;

        int getValue() const;
    private:
        int value;
};
#endif //Shape_Impl_Header
