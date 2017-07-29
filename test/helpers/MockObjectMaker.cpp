#include <MockObjectMaker.h>
#include <stdexcept>
#include <iostream>

#include <memory>
#include <utility>
#include <sstream>

const unsigned int MockObjectMaker::EDGE=0;
const unsigned int MockObjectMaker::FACE=1;
unsigned int MockObjectMaker::EDGE_COUNT;
unsigned int MockObjectMaker::FACE_COUNT;

MockObjectMaker::MockObjectMaker()
{
}

Edge MockObjectMaker::makeEdge(){
    int name = this->getValue(EDGE);
    return Edge(name);
}

Face MockObjectMaker::makeFace(){
    std::vector<Edge> Edges;

    for(int i=1; i<=4; i++){
        int val = this->getValue(EDGE);
        Edges.push_back(Edge(val));
    }
    return this->makeFace(Edges);
}

Face MockObjectMaker::makeFace(Edge anEdge){
    Face aFace = this->makeFace();
    aFace.myEdges[0] = anEdge;
    return aFace;
}

Face MockObjectMaker::makeFace(Edge anEdge, int which){
    Face aFace = this->makeFace();
    aFace.myEdges[which] = anEdge;
    return aFace;
}

Face MockObjectMaker::makeFace(std::vector<Edge> Edges){
    int name  = this->getValue(FACE);
    Face aFace = Face(name, Edges);
    return aFace;
}

Box MockObjectMaker::makeBox(){
    unsigned int frt, bck, top, bot, lft, rgt;
    std::vector<Face> Faces;

    frt = boxFaces.front;
    bck = boxFaces.back;
    top = boxFaces.top;
    bot = boxFaces.bottom;
    lft = boxFaces.left;
    rgt = boxFaces.right;

    for(int i=1; i<=6; i++){
        Face aFace = this->makeFace();
        Faces.push_back(aFace);
    }

    Faces[top].myEdges[0] = Faces[frt].myEdges[0];
    Faces[bot].myEdges[0] = Faces[frt].myEdges[1];
    Faces[lft].myEdges[0] = Faces[frt].myEdges[2];
    Faces[rgt].myEdges[0] = Faces[frt].myEdges[3];

    Faces[top].myEdges[1] = Faces[bck].myEdges[0];
    Faces[bot].myEdges[1] = Faces[bck].myEdges[1];
    Faces[lft].myEdges[1] = Faces[bck].myEdges[2];
    Faces[rgt].myEdges[1] = Faces[bck].myEdges[3];

    Faces[lft].myEdges[2] = Faces[top].myEdges[2];
    Faces[rgt].myEdges[2] = Faces[top].myEdges[3];

    Faces[lft].myEdges[3] = Faces[bot].myEdges[2];
    Faces[rgt].myEdges[3] = Faces[bot].myEdges[3];

    return Box(Faces);
}

//FakePartFillet MockObjectMaker::FilletedBox(){
    //unsigned int frt, top, lft, rgt;

    //// Start with a box
    //FakePartFeature box = this->Box();

    //// Need a new face, since the fillet (or chamfer) creates a face
    //FakeOCCFace filletFace = this->makeFace();

    //// Fillet shares an Edge with four of the box faces.
    //frt = boxFaces.front;
    //top = boxFaces.top;
    //lft = boxFaces.left;
    //rgt = boxFaces.right;

    //unsigned int val1, val2, val3, val4;
    //val1 = this->getValue(FACE);
    //val2 = this->getValue(FACE);
    //val3 = this->getValue(FACE);
    //val4 = this->getValue(FACE);
    //FakeOCCFace Face1(val1), Face2(val2), Face3(val3), Face4(val4);
    //Face1 = box.Shape.Faces[frt];
    //Face2 = box.Shape.Faces[top];
    //Face3 = box.Shape.Faces[lft];
    //Face4 = box.Shape.Faces[rgt];

    //Face1.myEdges[0] = filletFace.myEdges[0];
    //Face2.myEdges[0] = filletFace.myEdges[1];
    //Face3.myEdges.push_back(filletFace.myEdges[2]);
    //Face4.myEdges.push_back(filletFace.myEdges[3]);

    //box.Shape.Faces[frt] = Face1;
    //box.Shape.Faces[top] = Face2;
    //box.Shape.Faces[lft] = Face3;
    //box.Shape.Faces[rgt] = Face4;

    //FakePartFillet fillet(box.Shape, filletFace);
    //return fillet;
//}

//FakePartFeature MockObjectMaker::Cylinder(){
    //std::vector<FakeOCCEdge> Edges, EdgesTop, EdgesBot;
    //for (int i=1; i<=3; i++){
        //FakeOCCEdge anEdge = this->makeEdge();
        //Edges.push_back(anEdge);
    //}

    //EdgesTop.push_back(Edges[0]);
    //EdgesBot.push_back(Edges[1]);

    //unsigned int val1, val2, val3;
    //val1 = this->getValue(FACE);
    //val2 = this->getValue(FACE);
    //val3 = this->getValue(FACE);

    //FakeOCCFace bot_face(val1, EdgesBot);
    //FakeOCCFace top_face(val2, EdgesTop);
    //FakeOCCFace lat_face(val3, Edges);

    //std::vector<FakeOCCFace> Faces;
    //Faces.push_back(bot_face);
    //Faces.push_back(top_face);
    //Faces.push_back(lat_face);

    //FakePartFeature mock_feature = FakePartFeature();
    //mock_feature.Shape.Faces = Faces;
    //return mock_feature;
//}

//---------------------------------------------------------------------------
//          private methods
//---------------------------------------------------------------------------

int MockObjectMaker::getValue(unsigned int which) const{
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
