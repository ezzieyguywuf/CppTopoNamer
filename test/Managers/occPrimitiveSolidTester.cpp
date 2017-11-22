#include <gtest/gtest.h>

#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopExp.hxx>
#include <TopAbs_ShapeEnum.hxx>

#include <Managers/PrimitiveSolid.h>
#include <Topology/ISolid.h>
#include <Topology/IEdge.h>
#include <OccTopology/OccSolid.h>
#include <OccTopology/OccFace.h>
#include <OccTopology/OccEdge.h>

#include <OccObjectMaker.h>

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
              myOccISolid(myOccManager->getManagedSolid()),
              myOccSolid(static_cast<const OccSolid&>(*myOccISolid))
        {
        };
        
        OccObjectMaker occMaker;
        ISolidManager* myOccManager;
        const unique_ptr<ISolid>& myOccISolid;
        const OccSolid& myOccSolid;
};

TEST_F(PrimitiveSolidTester, occ_getIndex){
    Manager::FaceIndex anIndex0(0);
    Manager::FaceIndex anIndex1(3);
    Manager::FaceIndex anIndex2(5);
    EXPECT_EQ(anIndex0, myOccManager->getIndex(myOccISolid->getFaces()[0]));
    EXPECT_EQ(anIndex1, myOccManager->getIndex(myOccISolid->getFaces()[3]));
    EXPECT_EQ(anIndex2, myOccManager->getIndex(myOccISolid->getFaces()[5]));
}

TEST_F(PrimitiveSolidTester, emptyEdgeCrash){
    TopTools_IndexedMapOfShape edges;
    TopExp::MapShapes(myOccSolid.getShape(), TopAbs_EDGE, edges);
    TopoDS_Edge anEdge = TopoDS::Edge(edges.FindKey(1));
    std::unique_ptr<IEdge> anIEdge(new OccEdge(anEdge));
    Manager::EdgeIndex anIndex = myOccManager->getIndex(anIEdge);
}
