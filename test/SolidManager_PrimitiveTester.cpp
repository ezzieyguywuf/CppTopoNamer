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
    EXPECT_EQ(myManager->getIndex(boxFaces[0]).get(), 0);
    EXPECT_EQ(myManager->getIndex(boxFaces[1]).get(), 1);
    EXPECT_EQ(myManager->getIndex(boxFaces[3]).get(), 3);

    const int top = MockObjectMaker::BoxFaces.at("top");
    const int back = MockObjectMaker::BoxFaces.at("back");
    const int front = MockObjectMaker::BoxFaces.at("front");

    // first edge on `top` face is equal to first edge on `front` face
    EXPECT_EQ(myManager->getIndex(boxFaces[front]->getEdges()[0]).get(), 0);
    EXPECT_EQ(myManager->getIndex(boxFaces[top]->getEdges()[0]).get(), 0);

    // second edge on `top` face is second edge overall
    EXPECT_EQ(myManager->getIndex(boxFaces[front]->getEdges()[1]).get(), 1);
    // first edge on `back` face is 4th edge overall
    EXPECT_EQ(myManager->getIndex(boxFaces[back]->getEdges()[0]).get(), 4);
    // second edge on `back` face is 5th edge overall
    EXPECT_EQ(myManager->getIndex(boxFaces[back]->getEdges()[1]).get(), 5);
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

TEST_F(SolidManagerTester, changeFaces)
{
    auto data = maker.increaseBoxHeight(myBox);
    std::unique_ptr<ISolidManager> newManager(new SolidManager::Primitive(std::move(std::get<0>(data))));
    myManager->updateSolid(std::move(newManager), std::get<1>(data));
}
