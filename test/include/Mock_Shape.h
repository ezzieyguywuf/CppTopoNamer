#ifndef MOCK_SHAPE_HEADER
#define MOCK_SHAPE_HEADER
#include <IShape.h>

#include <memory>

namespace mock{
    class Shape : public IShape
    {
        public:
            Shape(int value);
            ~Shape(){};

            bool operator==(std::unique_pointer<Shape> aShape) const;
            bool IsFlipped(std::unique_pointer<Shape> aShape) const;

            int getValue() const;
        private:
            int value;
    };
};
#endif /* ifndef MOCK_SHAPE_HEADER */
