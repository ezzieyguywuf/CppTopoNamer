#include <Shape.h>
#include <iostream>

int main()
{
    Shape shape1(1), shape2(1), shape3(2);
    bool val1, val2;
    val1 = shape1 == shape2;
    val2 = shape1 == shape3;
    std::cout << std::boolalpha;
    std::cout << "shape1 == shape2 = " << val1 << std::endl;
    std::cout << "shape1 == shape3 = " << val2 << std::endl;
    return 0;
}
