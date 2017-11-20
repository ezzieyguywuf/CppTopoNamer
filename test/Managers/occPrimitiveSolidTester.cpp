#include <gtest/gtest.h>
#include <Managers/PrimitiveSolid.h>
#include <OccObjectMaker.h>
#include <Topology/ISolid.h>
#include <OccTopology/OccFace.h>
#include <memory>
#include <vector>
#include <iostream>

using std::vector;
using std::unique_ptr;
using std::pair;

class PrimitiveSolidTester : public testing::Test{
    protected:
        PrimitiveSolidTester()
            : myOccManager(new Manager::PrimitiveSolid(occMaker.makeBox())),
              myOccBox(myOccManager->getManagedSolid())
        {
        };
        
        OccObjectMaker occMaker;
        ISolidManager* myOccManager;
        const unique_ptr<ISolid>& myOccBox;
};

TEST_F(PrimitiveSolidTester, occ_getIndex){
    Manager::FaceIndex anIndex0(0);
    Manager::FaceIndex anIndex1(3);
    Manager::FaceIndex anIndex2(5);
    EXPECT_EQ(anIndex0, myOccManager->getIndex(myOccBox->getFaces()[0]));
    EXPECT_EQ(anIndex1, myOccManager->getIndex(myOccBox->getFaces()[3]));
    EXPECT_EQ(anIndex2, myOccManager->getIndex(myOccBox->getFaces()[5]));
}

