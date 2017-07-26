#include <MockObjectMaker.h>
#include <stdexcept>
#include <iostream>

#include <memory>
#include <utility>
#include <sstream>

//using mock::Box;
using mock::Edge;
using mock::Face;
using mock::Shape;

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

Face MockObjectMaker::makeFace(std::vector<Edge> Edges){
    int name  = this->getValue(FACE);
    Face aFace = Face(name, Edges);
    return aFace;
}

//Box MockObjectMaker::makeBox(){
    //unsigned int frt, bck, top, bot, lft, rgt;
    //std::vector<mock::TopoDS_Face> Faces;

    //frt = boxFaces.front;
    //bck = boxFaces.back;
    //top = boxFaces.top;
    //bot = boxFaces.bottom;
    //lft = boxFaces.left;
    //rgt = boxFaces.right;

    //for(int i=1; i<=6; i++){
        //mock::TopoDS_Face aFace = this->makeFace();
        //Faces.push_back(aFace);
    //}

    //Faces[top].Edges[0] = Faces[frt].Edges[0];
    //Faces[bot].Edges[0] = Faces[frt].Edges[1];
    //Faces[lft].Edges[0] = Faces[frt].Edges[2];
    //Faces[rgt].Edges[0] = Faces[frt].Edges[3];

    //Faces[top].Edges[1] = Faces[bck].Edges[0];
    //Faces[bot].Edges[1] = Faces[bck].Edges[1];
    //Faces[lft].Edges[1] = Faces[bck].Edges[2];
    //Faces[rgt].Edges[1] = Faces[bck].Edges[3];

    //Faces[lft].Edges[2] = Faces[top].Edges[2];
    //Faces[rgt].Edges[2] = Faces[top].Edges[3];

    //Faces[lft].Edges[3] = Faces[bot].Edges[2];
    //Faces[rgt].Edges[3] = Faces[bot].Edges[3];

    //Box mock_box = Box();
    //mock_box.Faces = Faces;
    //return mock_box;
//}

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

    //Face1.Edges[0] = filletFace.Edges[0];
    //Face2.Edges[0] = filletFace.Edges[1];
    //Face3.Edges.push_back(filletFace.Edges[2]);
    //Face4.Edges.push_back(filletFace.Edges[3]);

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
