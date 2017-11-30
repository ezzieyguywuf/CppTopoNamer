#ifndef MOCK_OBJECT_MAKER
#define MOCK_OBJECT_MAKER

#include <vector>
#include <string>
#include <memory> // for unique_ptr
#include <map>
#include <tuple>
#include <utility> // for std::pair

#include <Topology/IEdge.h>
#include <Topology/IFace.h>
#include <Topology/ISolid.h>
#include <Topology/ISolidManager.h>
#include <Mock_Edge.h>
#include <Mock_Face.h>
#include <Mock_Solid.h>

using std::tuple;
using std::unique_ptr;
using std::vector;
using std::pair;
using Manager::FaceIndex;

class MockObjectMaker{
    public:
        MockObjectMaker();
        ~MockObjectMaker(){};

        unique_ptr<IEdge> makeEdge();
        unique_ptr<IFace> makeFace();
        //unique_ptr<IFace> makeFace(Edge anEdge);
        //unique_ptr<IFace> makeFace(Edge anEdge, int index);
        unique_ptr<IFace> makeFace(std::vector<Mock::Edge> Edges);
        unique_ptr<ISolid> makeBox();
        unique_ptr<ISolid> makeCylinder();
        // As a result of this operation, origBox should have the same number of Faces,
        // however each Face should be different (per the current FreeCAD implementation)
        tuple<unique_ptr<ISolid>, vector<pair<FaceIndex, FaceIndex>>> 
            increaseBoxHeight(const ISolid& origBox);
        // As a result of this operation, origBox will have one additional face and three
        // modified faces. We should change the ordering of the faces too to match what
        // happens in FreeCAD
        //tuple<unique_ptr<ISolid>, vector<pair<FaceIndex, FaceIndex>>>
            //fuseTallerCylinder(const ISolid& origBox);
        //unique_ptr<ISolid> filletBox(
                //const unique_ptr<ISolid>& aBox,
                //const unique_ptr<IEdge>& anEdge);
        //Shape makeFilletedBox();

        static const std::map<std::string, int> BoxFaces; 
        static const std::map<std::string, int> CylFaces; 
        static const std::map<std::string, int> FusTallFaces; 
    private:
        Mock::Face makeMockFace(unsigned int num_edges=4);
        Mock::Edge makeMockEdge();
        std::vector<Mock::Edge> makeMockEdges(unsigned int count=4);
        std::vector<Mock::Face> buildBoxFaces();
        // creates a unique value for each Face, Edge, etc.
        int getValue(unsigned int which) const;

        static const unsigned int EDGE;
        static const unsigned int FACE;

        static unsigned int EDGE_COUNT;
        static unsigned int FACE_COUNT;


};
#endif //MOCK_OBJECT_MAKER
