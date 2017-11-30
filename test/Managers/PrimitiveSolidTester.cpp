#include <gtest/gtest.h>
#include <Managers/PrimitiveSolid.h>
#include <MockObjectMaker.h>
#include <Topology/ISolid.h>
#include <memory>
#include <vector>
#include <iostream>

using std::vector;
using std::unique_ptr;
using std::pair;

class PrimitiveSolidTester : public testing::Test{
    protected:
        PrimitiveSolidTester()
            : myManager(new Manager::PrimitiveSolid(maker.makeBox())),
              myBox(myManager->getManagedSolid())
        {
        };
        
        MockObjectMaker maker;
        ISolidManager* myManager;
        const ISolid& myBox;
};

TEST_F(PrimitiveSolidTester, getIndex){
    EXPECT_EQ(myManager->getIndex(myBox.getFace(0)).get(), 0);
    EXPECT_EQ(myManager->getIndex(myBox.getFace(1)).get(), 1);
    EXPECT_EQ(myManager->getIndex(myBox.getFace(3)).get(), 3);

    const int top = MockObjectMaker::BoxFaces.at("top");
    const int back = MockObjectMaker::BoxFaces.at("back");
    const int front = MockObjectMaker::BoxFaces.at("front");

    // first edge on `top` face is equal to first edge on `front` face
    EXPECT_EQ(myManager->getIndex(myBox.getFace(front).getEdge(0)).get(), 0);
    EXPECT_EQ(myManager->getIndex(myBox.getFace(top).getEdge(0)).get(), 0);

    // second edge on `top` face is second edge overall
    EXPECT_EQ(myManager->getIndex(myBox.getFace(front).getEdge(1)).get(), 1);
    // first edge on `back` face is 4th edge overall
    EXPECT_EQ(myManager->getIndex(myBox.getFace(back).getEdge(0)).get(), 4);
    // second edge on `back` face is 5th edge overall
    EXPECT_EQ(myManager->getIndex(myBox.getFace(back).getEdge(1)).get(), 5);
}

TEST_F(PrimitiveSolidTester, getEdge){
    const int top = MockObjectMaker::BoxFaces.at("top");
    const int back = MockObjectMaker::BoxFaces.at("back");
    const int front = MockObjectMaker::BoxFaces.at("front");

    EXPECT_EQ(myManager->getEdge(0) , myBox.getFace(front).getEdge(0));
    EXPECT_EQ(myManager->getEdge(1) , myBox.getFace(front).getEdge(1));
    EXPECT_EQ(myManager->getEdge(4) , myBox.getFace(back).getEdge(0));
    EXPECT_EQ(myManager->getEdge(5) , myBox.getFace(back).getEdge(1));
    EXPECT_EQ(myManager->getEdge(8) , myBox.getFace(top).getEdge(2));
}

TEST_F(PrimitiveSolidTester, changeFaces_checkFaces)
{
    // all the faces should be new, but in the same position. This simulates FreeCAD,
    // which creates an entirely new TopoDS_Solid for all operations, include changing the
    // height of a box.
    auto data = maker.increaseBoxHeight(myBox);
    unique_ptr<ISolid> newBox(std::move(std::get<0>(data)));
    vector<pair<Manager::FaceIndex, Manager::FaceIndex>> 
        newFaces = std::get<1>(data);

    // get an index, then update our PrimitiveSolid with the new solid and list of changed
    // faces
    const IFace& origFront = myBox.getFace(MockObjectMaker::BoxFaces.at("front"));
    const IFace& newFront  = newBox->getFace(MockObjectMaker::BoxFaces.at("front"));
    Manager::FaceIndex index = myManager->getIndex(origFront);
    myManager->updateSolid(std::move(newBox), newFaces);

    // finally, check the return value from the updated PrimitiveSolid
    EXPECT_NE(origFront, myManager->getFace(index));
    EXPECT_EQ(newFront, myManager->getFace(index));
}

TEST_F(PrimitiveSolidTester, changeFaces_checkEdges)
{
    // all the faces should be new, but in the same position. This simulates FreeCAD,
    // which creates an entirely new TopoDS_Solid for all operations, include changing the
    // height of a box.
    auto data = maker.increaseBoxHeight(myBox);
    unique_ptr<ISolid> newBox(std::move(std::get<0>(data)));
    vector<pair<Manager::FaceIndex, Manager::FaceIndex>> 
        newFaces = std::get<1>(data);

    // get an index, then update our PrimitiveSolid with the new solid and list of changed
    // faces. The zeroeth edge ont he front face should be the edge shared by the front
    // and top faces. This is based on how MockObjectMaker works.
    const IEdge& origEdge = 
        myBox.getFace(MockObjectMaker::BoxFaces.at("front")).getEdge(0);
    const IEdge& newEdge = 
        newBox->getFace(MockObjectMaker::BoxFaces.at("front")).getEdge(0);
    Manager::EdgeIndex index = myManager->getIndex(origEdge);
    myManager->updateSolid(std::move(newBox), newFaces);

    // finally, check the return value from the updated PrimitiveSolid
    EXPECT_NE(origEdge, myManager->getEdge(index));
    EXPECT_EQ(newEdge, myManager->getEdge(index));
}

TEST_F(PrimitiveSolidTester, AddFaces)
{
    // A face can be added by calling ISolidManager::updateSolid. The list of faces should
    // include a "null" Manager::FaceIndex as the first value in the pair in order to
    // indicate a new face.
    auto data = maker.fuseTallerCylinder();
    unique_ptr<ISolid> newBox(std::move(std::get<0>(data)));
    vector<pair<Manager::FaceIndex, Manager::FaceIndex>> 
        newFaces = std::get<1>(data);
    myManager->updateSolid(std::move(newBox), newFaces);
}
