#include <MockObjectMaker.h>
#include <Mock_Edge.h>
#include <iostream>
#include <memory>

int main()
{
    MockObjectMaker myMaker;
    //Face myFace = myMaker.makeFace();
    std::unique_ptr<IEdge> myEdge = myMaker.makeEdge();
    IEdge* checkEdge = new Mock::Edge(1);

    
    std::cout << "(*myEdge == *checkEdge) -> ";
    std::cout << ((*myEdge == *checkEdge) ? "true" : "false");
    std::cout << std::endl; 

    //Box myBox   = myMaker.makeBox();
    //std::cout << "myFace value = " << myFace.getValue() << std::endl;
    
    //std::cout << "myBox.myFaces[0] value = " << myBox.myFaces[0].getValue() << std::endl;
    //std::cout << "myBox.myFaces[1] value = " << myBox.myFaces[1].getValue() << std::endl;
    //std::cout << "myBox.myFaces[2] value = " << myBox.myFaces[2].getValue() << std::endl;
    //std::cout << "myBox.myFaces[0].myEdges[0] value = " << myBox.myFaces[0].myEdges[0].getValue() << std::endl;
    //std::cout << "myBox.myFaces[0].myEdges[1] value = " << myBox.myFaces[0].myEdges[1].getValue() << std::endl;
    //std::cout << "myBox.myFaces[0].myEdges[2] value = " << myBox.myFaces[0].myEdges[2].getValue() << std::endl;
}
