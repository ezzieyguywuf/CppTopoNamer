#ifndef MOCK_OBJECT_MAKER
#define MOCK_OBJECT_MAKER
// This flag will indicate to our production code that it should use some of our mocked
// classes
#ifndef UNIT_TESTING
#define UNIT_TESTING
#endif

#include <vector>
#include <string>

#include <Mock_TopoDS_Shape.h>
#include <Mock_TopoDS_Edge.h>
#include <Mock_TopoDS_Face.h>
#include <Box.h>

//#include <FakeIt.hpp>

//class FakeOCCShape;
//class FakePartFeature;
//class FakePartFillet;
//namespace mock{class TopExp_Explorer;}

namespace mock{
    class MockObjectMaker{
        public:
            MockObjectMaker(){};
            ~MockObjectMaker(){};

            TopoDS_Edge makeEdge();
            TopoDS_Face makeFace();
            TopoDS_Face makeFace(std::vector<TopoDS_Edge> Edges);
            Box makeBox();
            TopoDS_Shape makeFilletedBox();
            TopoDS_Shape makeCylinder();

        private:
            // Will return a value to use for the IsEqual and IsSame comparison. This ensures
            // that every time we ask for an OCCObject it is 'unique'
            unsigned int getValue(unsigned int which) const;

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
}

//namespace mock{
    //class TopExp_Explorer{
        //public:
            //TopExp_Explorer(const FakeOCCFace& aFace, const TopAbs_ShapeEnum toFind);
            //// TODO: add other constructors as needed, i.e. for FakeOCCShape
            //bool More() const;
            //void Next() const;
            //FakeOCCShape Current() const;

        //private:
            //FakeOCCShape myShape;
            //std::vector<FakeOCCShape> mySubShapes;
            //unsigned int index;
    //};
//}

//class FakeOCCShape{
    //public:
        //FakeOCCShape(){};
        //~FakeOCCShape(){};

        //std::vector<FakeOCCFace> Faces;
//};

//class FakePartFeature{
    //public:
        //FakePartFeature(){};
        //~FakePartFeature(){};

        //FakeOCCShape Shape;
//};

//class FakePartFillet : FakePartFeature{
    //public:
        //FakePartFillet(const FakeOCCShape& base, const FakeOCCFace& filletFace);
        //~FakePartFillet(){};
        //FakeOCCFace getFilletFace();
    //private:
        //FakeOCCFace filletFace;
//};
#endif //MOCK_OBJECT_MAKER
