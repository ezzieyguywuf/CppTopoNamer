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
        // This essentially makes a box with two extra faces. The first extra face is the
        // lateral portion of the cylinder. The Second extra face is the top portion of
        // the cylinder, which extends beyond the top of the box. The bottom of the
        // cylinder is co-planar with the bottom of the box. The center of the cylinder is
        // coincident with one of the edges of the box and the radius of the cylinder is
        // less than the length of the edges of the box, thus the lateral face is present
        // in the fused solid.
        tuple<unique_ptr<ISolid>, vector<pair<FaceIndex, FaceIndex>>>
            fuseTallerCylinder();
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
