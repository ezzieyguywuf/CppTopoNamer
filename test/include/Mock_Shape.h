#ifndef MOCK_SHAPE_HEADER
#define MOCK_SHAPE_HEADER

#include <IShape.h>

#include <memory>

namespace mock{
    class Shape : public IShape
    {
        public:
            Shape(int value);

            bool operator==(const Shape& aShape) const;
            bool IsFlipped(const Shape& aShape) const;
            bool operator==(const IShape& aShape) const {};
            bool IsFlipped(const IShape& aShape) const {};

            int getValue() const;
        private:
            int value;
    };
};
#endif /* ifndef MOCK_SHAPE_HEADER */
