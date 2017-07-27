#include <Face.h>
#include <Edge.h>
#include <vector>
#include <iostream>

int main()
{
    Edge edge1(1), edge2(2);
    std::vector<Edge> edges1, edges2;
    edges1.push_back(edge1);
    edges2.push_back(edge2);
    Face face1(1, edges1), face2(1, edges1), face3(2, edges2);
    bool val1, val2;
    val1 = face1 == face2;
    val2 = face1 == face3;
    std::cout << std::boolalpha;
    std::cout << "face1==face2 = " << val1 << std::endl;
    std::cout << "face1==face3 = " << val2 << std::endl;
    return 0;
}
