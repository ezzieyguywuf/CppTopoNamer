#include <MockObjectMaker.h>
#include <iostream>

int main()
{
    MockObjectMaker myMaker;
    Face myFace = myMaker.makeFace();
    Edge myEdge = myMaker.makeEdge();
    Box myBox   = myMaker.makeBox();
    std::cout << "myFace value = " << myFace.getValue() << std::endl;
    std::cout << "myEdge value = " << myEdge.getValue() << std::endl;
    std::cout << "myBox.myFaces[0] value = " << myBox.myFaces[0].getValue() << std::endl;
    std::cout << "myBox.myFaces[1] value = " << myBox.myFaces[1].getValue() << std::endl;
    std::cout << "myBox.myFaces[2] value = " << myBox.myFaces[2].getValue() << std::endl;
    std::cout << "myBox.myFaces[0].myEdges[0] value = " << myBox.myFaces[0].myEdges[0].getValue() << std::endl;
    std::cout << "myBox.myFaces[0].myEdges[1] value = " << myBox.myFaces[0].myEdges[1].getValue() << std::endl;
    std::cout << "myBox.myFaces[0].myEdges[2] value = " << myBox.myFaces[0].myEdges[2].getValue() << std::endl;
}
