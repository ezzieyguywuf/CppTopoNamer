#ifndef MOCK_OBJECT_MAKER
#define MOCK_OBJECT_MAKER

#include <vector>
#include <string>

#include <Mock_Shape.h>
#include <Mock_Edge.h>
#include <Mock_Face.h>
//#include <Mock_Box.h>

using mock::Shape;
using mock::Edge;
using mock::Face;
//using mock::Box;

class MockObjectMaker{
    public:
        MockObjectMaker();
        ~MockObjectMaker(){};

        Edge makeEdge();
        Face makeFace();
        Face makeFace(std::vector<Edge> Edges);
        //Box makeBox();
        //Shape makeFilletedBox();
        //Shape makeCylinder();

    private:
        // creates a unique value for each Face, Edge, etc.
        int getValue(unsigned int which) const;

        struct BoxFaces{
            static const unsigned int front   = 0;
            static const unsigned int back    = 1;
            static const unsigned int top     = 2;
            static const unsigned int bottom  = 3;
            static const unsigned int left    = 4;
            static const unsigned int right   = 5;
        }boxFaces;


        static const unsigned int EDGE;
        static const unsigned int FACE;

        static unsigned int EDGE_COUNT;
        static unsigned int FACE_COUNT;


};
#endif //MOCK_OBJECT_MAKER
