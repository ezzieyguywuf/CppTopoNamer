#include <Mock_Edge.h>
#include <Mock_Face.h>
#include <Topology/IEdge.h>
#include <Topology/IFace.h>
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

    std::vector<Edge> edges1, edges2;
    edges1.push_back(*edge1);
    edges1.push_back(*edge2);
    //edges2.push_back(*edge2);
    //edges2.push_back(*edge3);

    Face* face1 = new Face(1, edges1);
    //Face* face2 = new Face(2, edges2);

    // client 
    const edgeVector& allEdges = edges;
    IFace& aFace = *face1;
    //IFace& bFace = *face2;
    IEdge& aEdge = *edge1;
    IEdge& bEdge = *edge2;
    IEdge& cEdge = *edge3;
    const edgeVector& checkEdges = aFace.getEdges();

    std::cout << "(*edges[0]) == (*checkEdges[0]) -> ";
    std::cout << ((*edges[0]) == (*checkEdges[0]) ? "true" : "false");
    std::cout << " || Expecting -> " << "true";
    std::cout << std::endl; 

    std::cout << "(*edges[1]) == (*checkEdges[0]) -> ";
    std::cout << ((*edges[1]) == (*checkEdges[0]) ? "true" : "false");
    std::cout << " || Expecting -> " << "false";
    std::cout << std::endl; 

    std::cout << "(*edges[2]) == (*checkEdges[0]) -> ";
    std::cout << ((*edges[2]) == (*checkEdges[0]) ? "true" : "false");
    std::cout << " || Expecting -> " << "true";
    std::cout << std::endl; 
    return 0;
}
