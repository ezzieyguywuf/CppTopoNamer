#ifndef MOCK_OBJECT_MAKER
#define MOCK_OBJECT_MAKER

#include <vector>
#include <string>
#include <memory>
#include <map>

#include <IEdge.h>
#include <IFace.h>
#include <ISolid.h>
#include <Mock_Edge.h>
#include <Mock_Face.h>
#include <Mock_Solid.h>

class MockObjectMaker{
    public:
        MockObjectMaker();
        ~MockObjectMaker(){};

        std::unique_ptr<IEdge> makeEdge();
        std::unique_ptr<IFace> makeFace();
        //std::unique_ptr<IFace> makeFace(Edge anEdge);
        //std::unique_ptr<IFace> makeFace(Edge anEdge, int index);
        std::unique_ptr<IFace> makeFace(std::vector<Mock::Edge> Edges);
        std::unique_ptr<ISolid> makeBox();
        //Shape makeFilletedBox();
        //Shape makeCylinder();

        static const std::map<std::string, int> BoxFaces; 
    private:
        Mock::Face makeMockFace();
        Mock::Edge makeMockEdge();
        std::vector<Mock::Edge> makeMockEdges();
        // creates a unique value for each Face, Edge, etc.
        int getValue(unsigned int which) const;

        static const unsigned int EDGE;
        static const unsigned int FACE;

        static unsigned int EDGE_COUNT;
        static unsigned int FACE_COUNT;


};
#endif //MOCK_OBJECT_MAKER
