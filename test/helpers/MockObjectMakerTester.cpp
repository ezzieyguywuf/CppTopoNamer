#include <MockObjectMaker.h>
#include <Mock_Edge.h>
#include <iostream>
#include <memory>

int main()
{
    // factory
    std::vector<Mock::Edge> edges;
    edges.push_back(Mock::Edge(2));
    IEdge* checkEdge = new Mock::Edge(1);
    IFace* checkFace = new Mock::Face(1, edges);
    IFace* solidFace = new Mock::Face(2, edges);

    // client
    MockObjectMaker myMaker;
    std::unique_ptr<IEdge> myEdge = myMaker.makeEdge();
    std::unique_ptr<IFace> myFace = myMaker.makeFace();
    std::unique_ptr<ISolid> myBox  = myMaker.makeBox();
    const std::vector<std::unique_ptr<IFace>>& boxFaces = myBox->getFaces();
    
    std::cout << "(*myEdge == *checkEdge) -> ";
    std::cout << ((*myEdge == *checkEdge) ? "true" : "false");
    std::cout << std::endl; 

    
    std::cout << "(*myFace == *checkFace) -> ";
    std::cout << ((*myFace == *checkFace) ? "true" : "false");
    std::cout << std::endl; 

    
    std::cout << "*boxFaces[0] == *solidFace -> ";
    std::cout << (*boxFaces[0] == *solidFace ? "true" : "false");
    std::cout << " || Expecting -> " << "true";
    std::cout << std::endl; 

    int frtIndex = MockObjectMaker::BoxFaces.at("front");
    int topIndex = MockObjectMaker::BoxFaces.at("top");
    const std::vector<std::unique_ptr<IEdge>>& frtEdges = boxFaces[frtIndex]->getEdges();
    const std::vector<std::unique_ptr<IEdge>>& topEdges = boxFaces[topIndex]->getEdges();

    
    std::cout << "*frtEdges[0] == *topEdges[0] -> ";
    std::cout << (*frtEdges[0] == *topEdges[0] ? "true" : "false");
    std::cout << " || Expecting -> " << "true";
    std::cout << std::endl; 

    std::cout << "*frtEdges[0] == *topEdges[1] -> ";
    std::cout << (*frtEdges[0] == *topEdges[1] ? "true" : "false");
    std::cout << " || Expecting -> " << "false";
    std::cout << std::endl; 

}
