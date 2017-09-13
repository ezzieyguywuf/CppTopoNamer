#include <Topology/IFace.h>
#include <Mock_Solid.h>
#include <Mock_Face.h>
#include <Mock_Edge.h>
#include <vector>
#include <iostream>

#include <memory>

int main(){
    std::vector<Mock::Edge> edges;
    edges.push_back(Mock::Edge(1));
    edges.push_back(Mock::Edge(2));
    edges.push_back(Mock::Edge(3));
    std::vector<Mock::Face> faces;
    faces.push_back(Mock::Face(1, edges));
    faces.push_back(Mock::Face(2, edges));
    faces.push_back(Mock::Face(3, edges));

    const IFace& face1 = Mock::Face(1, edges);
    const IFace& face2 = Mock::Face(2, edges);
    const IFace& face3 = Mock::Face(3, edges);

    Mock::Solid mySolid(faces);
    const std::vector<std::unique_ptr<IFace>>& checkFaces = mySolid.getFaces();

    
    std::cout << "*checkFaces[0] == face1 -> ";
    std::cout << (*checkFaces[0] == face1 ? "true" : "false");
    std::cout << " || Expecting -> " << "true";
    std::cout << std::endl; 

    
    std::cout << "*checkFaces[0] == face2 -> ";
    std::cout << (*checkFaces[0] == face2 ? "true" : "false");
    std::cout << " || Expecting -> " << "false";
    std::cout << std::endl; 
    return 0;
}
