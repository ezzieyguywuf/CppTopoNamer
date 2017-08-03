#ifndef MOCK_OBJECT_MAKER
#define MOCK_OBJECT_MAKER

#include <vector>
#include <string>

//#include <Shape.h>
#include <IEdge.h>
#include <IFace.h>
#include <memory>
//#include <Box.h>

#include <Mock_Edge.h>
#include <Mock_Face.h>

class MockObjectMaker{
    public:
        MockObjectMaker();
        ~MockObjectMaker(){};

        std::unique_ptr<IEdge> makeEdge();
        std::unique_ptr<IFace> makeFace();
        //std::unique_ptr<IFace> makeFace(Edge anEdge);
        //std::unique_ptr<IFace> makeFace(Edge anEdge, int index);
        std::unique_ptr<IFace> makeFace(std::vector<Mock::Edge> Edges);
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
