#include <Mock_Edge.h>
#include <iostream>

using Mock::Edge;

int main()
{
    Edge edge1(1), edge2(1), edge3(2);
    bool val1, val2;
    val1 = edge1 == edge2;
    val2 = edge1 == edge3;
    std::cout << std::boolalpha;
    std::cout << "edge1==edge2 = " << val1 << ", expected TRUE"  << std::endl;
    std::cout << "edge1==edge3 = " << val2 << ", expected FALSE" << std::endl;
    return 0;
}
