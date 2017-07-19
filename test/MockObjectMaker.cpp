#include "MockObjectMaker.h"
#include <stdexcept>
#include <iostream>

unsigned int MockObjectMaker::EDGE_COUNT=0;
unsigned int MockObjectMaker::FACE_COUNT=0;
const unsigned int MockObjectMaker::EDGE=0;
const unsigned int MockObjectMaker::FACE=1;

FakeOCCEdge MockObjectMaker::OCCEdge(){
    unsigned int value;
    value = this->getValue(EDGE);
    FakeOCCEdge Edge(value);
    return Edge;
}

FakeOCCFace MockObjectMaker::OCCFace(){
    std::vector<FakeOCCEdge> Edges;

    for(int i=1; i<=4; i++){
        FakeOCCEdge edge = this->OCCEdge();
        Edges.push_back(edge);
    }
    return this->OCCFace(Edges);
}

FakeOCCFace MockObjectMaker::OCCFace(std::vector<FakeOCCEdge> Edges){
    unsigned int value;

    value = this->getValue(FACE);
    FakeOCCFace aFace = FakeOCCFace(value, Edges);
    return aFace;
}

FakePartFeature MockObjectMaker::Box(){
    unsigned int value;
    unsigned int frt, bck, top, bot, lft, rgt;
    std::vector<FakeOCCFace> Faces;

    frt = boxFaces.front;
    bck = boxFaces.back;
    top = boxFaces.top;
    bot = boxFaces.bottom;
    lft = boxFaces.left;
    rgt = boxFaces.right;

    for(int i=1; i<=6; i++){
        FakeOCCFace aFace = this->OCCFace();
        Faces.push_back(aFace);
    }

    Faces[top].Edges[0] = Faces[frt].Edges[0];
    Faces[bot].Edges[0] = Faces[frt].Edges[1];
    Faces[lft].Edges[0] = Faces[frt].Edges[2];
    Faces[rgt].Edges[0] = Faces[frt].Edges[3];

    Faces[top].Edges[1] = Faces[bck].Edges[0];
    Faces[bot].Edges[1] = Faces[bck].Edges[1];
    Faces[lft].Edges[1] = Faces[bck].Edges[2];
    Faces[rgt].Edges[1] = Faces[bck].Edges[3];

    Faces[lft].Edges[2] = Faces[top].Edges[2];
    Faces[rgt].Edges[2] = Faces[top].Edges[3];

    Faces[lft].Edges[3] = Faces[bot].Edges[2];
    Faces[rgt].Edges[3] = Faces[bot].Edges[3];

    FakePartFeature mock_feature = FakePartFeature();
    mock_feature.Shape.Faces = Faces;
    return mock_feature;
}

FakePartFillet MockObjectMaker::FilletedBox(){
    unsigned int frt, top, lft, rgt;

    // Start with a box
    FakePartFeature box = this->Box();

    // Need a new face, since the fillet (or chamfer) creates a face
    FakeOCCFace filletFace = this->OCCFace();

    // Fillet shares an Edge with four of the box faces.
    frt = boxFaces.front;
    top = boxFaces.top;
    lft = boxFaces.left;
    rgt = boxFaces.right;

    unsigned int val1, val2, val3, val4;
    val1 = this->getValue(FACE);
    val2 = this->getValue(FACE);
    val3 = this->getValue(FACE);
    val4 = this->getValue(FACE);
    FakeOCCFace Face1(val1), Face2(val2), Face3(val3), Face4(val4);
    Face1 = box.Shape.Faces[frt];
    Face2 = box.Shape.Faces[top];
    Face3 = box.Shape.Faces[lft];
    Face4 = box.Shape.Faces[rgt];

    Face1.Edges[0] = filletFace.Edges[0];
    Face2.Edges[0] = filletFace.Edges[1];
    Face3.Edges.push_back(filletFace.Edges[2]);
    Face4.Edges.push_back(filletFace.Edges[3]);

    box.Shape.Faces[frt] = Face1;
    box.Shape.Faces[top] = Face2;
    box.Shape.Faces[lft] = Face3;
    box.Shape.Faces[rgt] = Face4;

    FakePartFillet fillet(box.Shape, filletFace);
    return fillet;
}

FakePartFeature MockObjectMaker::Cylinder(){
    std::vector<FakeOCCEdge> Edges, EdgesTop, EdgesBot;
    for (int i=1; i<=3; i++){
        FakeOCCEdge anEdge = this->OCCEdge();
        Edges.push_back(anEdge);
    }

    EdgesTop.push_back(Edges[0]);
    EdgesBot.push_back(Edges[1]);

    unsigned int val1, val2, val3;
    val1 = this->getValue(FACE);
    val2 = this->getValue(FACE);
    val3 = this->getValue(FACE);

    FakeOCCFace bot_face(val1, EdgesBot);
    FakeOCCFace top_face(val2, EdgesTop);
    FakeOCCFace lat_face(val3, Edges);

    std::vector<FakeOCCFace> Faces;
    Faces.push_back(bot_face);
    Faces.push_back(top_face);
    Faces.push_back(lat_face);

    FakePartFeature mock_feature = FakePartFeature();
    mock_feature.Shape.Faces = Faces;
    return mock_feature;
}

unsigned int MockObjectMaker::getValue(unsigned int which) const{
    switch (which) {
        case EDGE:
            EDGE_COUNT++;
            return EDGE_COUNT;
        case FACE:
            FACE_COUNT++;
            return FACE_COUNT;
        default:
            throw std::invalid_argument("which must be EDGE or FACE");
    }
}

BaseFakeOCCObject::BaseFakeOCCObject(unsigned int value)
{
    this->value = value;
}

bool BaseFakeOCCObject::isEqual(const BaseFakeOCCObject& check) const{
    return this->getValue() == check.getValue();
}
bool BaseFakeOCCObject::isSame(const BaseFakeOCCObject& check) const{
    return this->isEqual(check);
}

unsigned int BaseFakeOCCObject::getValue() const{
    return this->value;
}

FakeOCCEdge::FakeOCCEdge(unsigned int value)
    : BaseFakeOCCObject(value){
}

FakeOCCFace::FakeOCCFace(unsigned int value)
    : BaseFakeOCCObject(value){
}

FakeOCCFace::FakeOCCFace(unsigned int value, std::vector<FakeOCCEdge> Edges)
    : BaseFakeOCCObject(value){
    this->Edges = Edges;
}

FakePartFillet::FakePartFillet(const FakeOCCShape& base, const FakeOCCFace& filletFace)
    : filletFace(filletFace)
{
    this->Shape = base;
}

int main(void){
    // let's test this ho.
    MockObjectMaker myMaker;
    FakeOCCEdge edge1 = myMaker.OCCEdge();
    FakeOCCEdge edge2 = myMaker.OCCEdge();
    FakeOCCFace face1 = myMaker.OCCFace();
    FakeOCCFace face2 = myMaker.OCCFace();
    FakePartFeature box = myMaker.Box();

    std::cout << "Hello, Wolfgang." << std::endl;
    std::cout << "edge1 value = " << edge1.getValue() <<std::endl;
    std::cout << "edge2 value = " << edge2.getValue() <<std::endl;
    std::cout << "face1 value = " << face1.getValue() <<std::endl;
    std::cout << "face2 value = " << face2.getValue() <<std::endl;
    std::cout << "box.Shape.Faces[0] value = " << box.Shape.Faces[0].getValue() <<std::endl;

    return 0;
}
