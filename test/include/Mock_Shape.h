#ifndef MOCK_SHAPE_HEADER
#define MOCK_SHAPE_HEADER

#include <IShape.h>

namespace mock
{
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
};
#endif //MOCK_SHAPE_HEADER
