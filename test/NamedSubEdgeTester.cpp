#include <gtest/gtest.h>
#include <MockObjectMaker.h>
#include <NamedSubEdge.h>
#include <NamedBaseFace.h>

class NamedEdgeTest : public testing::Test{
    protected:
        NamedEdgeTest()
            : mockEdge(maker.makeEdge()),
              namedEdge(mockEdge, "Edge000"){};
        virtual void SetUp()
        {
        }

        MockObjectMaker maker;
        Edge mockEdge;
        NamedSubEdge namedEdge;
};

TEST_F(NamedEdgeTest, isValid){
    EXPECT_EQ(namedEdge.isValid(), false);
}

TEST_F(NamedEdgeTest, addParent){
    Face mockFace = maker.makeFace();
    NamedBaseFace aFace(mockFace, "Face000");
    namedEdge.addParent(aFace);
    EXPECT_EQ(namedEdge.numParents(), 1);
}
