#include <MockObjectMaker.h>
#include <iostream>

int main()
{
    MockObjectMaker myMaker;
    mock::Face myFace = myMaker.makeFace();
    mock::Edge myEdge = myMaker.makeEdge();
    std::cout << "myFace value = " << myFace.getValue() << std::endl;
    std::cout << "myEdge value = " << myEdge.getValue() << std::endl;
}
