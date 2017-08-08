#include <gtest/gtest.h>
#include <SolidManager_Primitive.h>
#include <MockObjectMaker.h>
#include <ISolid.h>
#include <memory>
#include <vector>
#include <iostream>

using std::vector;
using std::unique_ptr;

class SolidManagerTester : public testing::Test{
    protected:
        SolidManagerTester()
            : myManager(new SolidManager::Primitive(std::move(maker.makeBox()))),
              myBox(myManager->getManagedSolid())
        {
        };
        
        MockObjectMaker maker;
        ISolidManager* myManager;
        const unique_ptr<ISolid>& myBox;
};

TEST_F(SolidManagerTester, getIndex){
    // Faces added in following order: front, back, top, bottom, left, right
    const vector<unique_ptr<IFace>>& boxFaces = myBox->getFaces();
    EXPECT_EQ(myManager->getIndex(boxFaces[0]), 0);
    EXPECT_EQ(myManager->getIndex(boxFaces[1]), 1);
    EXPECT_EQ(myManager->getIndex(boxFaces[3]), 3);

    const int top = MockObjectMaker::BoxFaces.at("top");
    const int back = MockObjectMaker::BoxFaces.at("back");
    const int front = MockObjectMaker::BoxFaces.at("front");

    // first edge on `top` face is equal to first edge on `front` face
    EXPECT_EQ(myManager->getIndex(boxFaces[front]->getEdges()[0]), 0);
    EXPECT_EQ(myManager->getIndex(boxFaces[top]->getEdges()[0]), 0);

    // second edge on `top` face is second edge overall
    EXPECT_EQ(myManager->getIndex(boxFaces[front]->getEdges()[1]), 1);
    // first edge on `back` face is 4th edge overall
    EXPECT_EQ(myManager->getIndex(boxFaces[back]->getEdges()[0]), 4);
    // second edge on `back` face is 5th edge overall
    EXPECT_EQ(myManager->getIndex(boxFaces[back]->getEdges()[1]), 5);
}

TEST_F(SolidManagerTester, getEdge){
    // Faces added in following order: front, back, top, bottom, left, right
    const vector<unique_ptr<IFace>>& boxFaces = myBox->getFaces();

    const int top = MockObjectMaker::BoxFaces.at("top");
    const int back = MockObjectMaker::BoxFaces.at("back");
    const int front = MockObjectMaker::BoxFaces.at("front");

    EXPECT_TRUE(*myManager->getEdge(0) == *boxFaces[front]->getEdges()[0]);
    EXPECT_TRUE(*myManager->getEdge(1) == *boxFaces[front]->getEdges()[1]);
    EXPECT_TRUE(*myManager->getEdge(4) == *boxFaces[back]->getEdges()[0]);
    EXPECT_TRUE(*myManager->getEdge(5) == *boxFaces[back]->getEdges()[1]);
    EXPECT_TRUE(*myManager->getEdge(8) == *boxFaces[top]->getEdges()[2]);
}

TEST_F(SolidManagerTester, changeFace)
{
    const Mock::Face* oldFrontFace = static_cast<const Mock::Face*>(myBox->getFaces()[0]);
    const Mock::Face* oldTopFace = static_cast<const Mock::Face*>(myBox->getFaces()[1]);
    Mock::Face newFrontFace(oldFrontFace); 
    Mock::Face newTopFace(oldTopFace); 
    const unique_ptr<IFace>& newEdge = maker.makeEdge();
    newFrontFace.changeEdge(0, newEdge);
    newTopFace.changeEdge(0, newEdge);
    myManager->modifyFace(0, newFace);
}
