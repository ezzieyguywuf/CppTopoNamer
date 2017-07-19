#include <vector>
#include <string>

class BaseFakeOCCObject{
    public:
        BaseFakeOCCObject(unsigned int value);
        ~BaseFakeOCCObject(){};

        bool isEqual(const BaseFakeOCCObject& check) const;
        bool isSame(const BaseFakeOCCObject& check) const;
        unsigned int getValue() const;
    private:
        unsigned int value;
};

class FakeOCCEdge : public BaseFakeOCCObject{
    public:
        FakeOCCEdge(unsigned int value);
        ~FakeOCCEdge(){};
};

class FakeOCCFace : public BaseFakeOCCObject{
    public:
        FakeOCCFace(unsigned int value);
        FakeOCCFace(unsigned int value, std::vector<FakeOCCEdge> Edges);
        ~FakeOCCFace(){};

        std::vector<FakeOCCEdge> Edges;
};

class FakeOCCShape{
    public:
        FakeOCCShape(){};
        ~FakeOCCShape(){};

        std::vector<FakeOCCFace> Faces;
};

class FakePartFeature{
    public:
        FakePartFeature(){};
        ~FakePartFeature(){};

        FakeOCCShape Shape;
};

class FakePartFillet : FakePartFeature{
    public:
        FakePartFillet(const FakeOCCShape& base, const FakeOCCFace& filletFace);
        ~FakePartFillet(){};
        FakeOCCFace getFilletFace();
    private:
        FakeOCCFace filletFace;
};

class MockObjectMaker{
    public:
        MockObjectMaker(){};
        ~MockObjectMaker(){};

        FakeOCCEdge OCCEdge();
        FakeOCCFace OCCFace();
        FakeOCCFace OCCFace(std::vector<FakeOCCEdge> Edges);
        FakePartFeature Box();
        FakePartFillet FilletedBox();
        FakePartFeature Cylinder();

    private:
        // Will return a value to use for the isEqual and isSame comparison. This ensures
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

