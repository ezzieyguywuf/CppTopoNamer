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
            : myManager(maker.makeBox()), myBox(myManager.getSolid())
        {
        };
        
        MockObjectMaker maker;
        SolidManager::Primitive myManager;
        const unique_ptr<ISolid>& myBox;
};

TEST_F(SolidManagerTester, getFaceIndex){
    const vector<unique_ptr<IFace>>& boxFaces = myBox->getFaces();
    EXPECT_EQ(myManager.getFaceIndex(boxFaces[0]), 0);
    EXPECT_EQ(myManager.getFaceIndex(boxFaces[1]), 1);
    EXPECT_EQ(myManager.getFaceIndex(boxFaces[3]), 3);
}
