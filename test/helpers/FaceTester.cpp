#include <Mock_Edge.h>
#include <Mock_Face.h>
#include <IEdge.h>
#include <IFace.h>
#include <vector>
#include <iostream>
#include <memory>

using Mock::Edge;
using Mock::Face;

int main()
{
    typedef std::vector<std::unique_ptr<IEdge>> edgeVector;
    // factory
    Edge* edge1 = new Edge(1);
    Edge* edge2 = new Edge(2);
    Edge* edge3 = new Edge(1);

    edgeVector edges;
    edges.push_back(std::move(std::unique_ptr<IEdge>(edge1)));
    edges.push_back(std::move(std::unique_ptr<IEdge>(edge2)));
    edges.push_back(std::move(std::unique_ptr<IEdge>(edge3)));

    std::vector<unsigned int> ind1 = {0, 1};
    std::vector<unsigned int> ind2 = {1, 2};

    Face* face1 = new Face(1, ind1);
    Face* face2 = new Face(2, ind2);

    // client 
    const edgeVector& allEdges = edges;
    IFace& aFace = *face1;
    IFace& bFace = *face2;
    IEdge& aEdge = *edge1;
    IEdge& bEdge = *edge2;
    IEdge& cEdge = *edge3;
    std::vector<unsigned int> ind;
    ind = aFace.getEdgeIndices();

    std::cout << "Checks for aFace" << std::endl;
    
    std::cout << "*allEdges[ind[0]] == aEdge -> ";
    std::cout << (*allEdges[ind[0]] == aEdge ? "true" : "false");
    std::cout << " || Expecting -> " << "true";
    std::cout << std::endl; 

    std::cout << "*allEdges[ind[1]] == aEdge -> ";
    std::cout << (*allEdges[ind[1]] == aEdge ? "true" : "false");
    std::cout << " || Expecting -> " << "false";
    std::cout << std::endl; 

    std::cout << "*allEdges[ind[1]] == bEdge -> ";
    std::cout << (*allEdges[ind[1]] == bEdge ? "true" : "false");
    std::cout << " || Expecting -> " << "true";
    std::cout << std::endl; 
    return 0;
}
