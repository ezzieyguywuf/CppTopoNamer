#ifndef MOCK_TOPODS_SHAPE
#define MOCK_TOPODS_SHAPE

#include<vector>

namespace mock{
    class TopoDS_Shape{
        public:
            TopoDS_Shape(){};
            TopoDS_Shape(unsigned int value);
            ~TopoDS_Shape(){};

            bool IsEqual(const TopoDS_Shape& check) const;
            bool IsSame(const TopoDS_Shape& check) const;
            unsigned int getValue() const;

        private:
            unsigned int value;
    };
}
#endif //MOCK_TOPODS_SHAPE
