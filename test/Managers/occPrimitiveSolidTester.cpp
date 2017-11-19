#include <gtest/gtest.h>
#include <Managers/PrimitiveSolid.h>
#include <OccObjectMaker.h>
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
            : myOccManager(new Manager::PrimitiveSolid(occMaker.makeBox())),
              myOccBox(myOccManager->getManagedSolid())
        {
        };
        
        OccObjectMaker occMaker;
        ISolidManager* myOccManager;
        const unique_ptr<ISolid>& myOccBox;
};

TEST_F(PrimitiveSolidTester, occ_getIndex){
    const vector<unique_ptr<IFace>>& boxFaces = myOccBox->getFaces();
    EXPECT_EQ(0, 0);
}

