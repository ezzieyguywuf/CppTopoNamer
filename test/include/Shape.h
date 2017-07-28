#ifndef Shape_Impl_Header
#define Shape_Impl_Header


#include <IShape.h>
#include <iostream>

class Shape : virtual public IShape<Shape>
{
    public:
        Shape(int value);

        bool operator==(const Shape& aShape) const override;
        bool IsFlipped(const Shape& aShape) const override;
        //std::ostream& operator<<(std::ostream& stream, const Shape& shape) const;

        int getValue() const;
    private:
        int value;
        static const std::string REPR;
};
#endif //Shape_Impl_Header
