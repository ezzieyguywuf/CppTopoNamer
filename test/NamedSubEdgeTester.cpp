#include <gtest/gtest.h>
#include <MockObjectMaker.h>
#include <NamedSubEdge.h>
#include <NamedBaseFace.h>

class NamedEdgeTest : public testing::Test{
    protected:
        NamedEdgeTest()
            : mockEdge(maker.makeEdge()),
              namedEdge(mockEdge, "Edge000"),
              f1(maker.makeFace(mockEdge), "Face000"),
              f2(maker.makeFace(mockEdge), "Face001"),
              f3(maker.makeFace(), "Face002")
        {};
        virtual void SetUp()
        {
        }

        MockObjectMaker maker;
        Edge mockEdge;
        NamedSubEdge namedEdge;
        NamedBaseFace f1, f2, f3;
};

TEST_F(NamedEdgeTest, isValid){
    EXPECT_EQ(namedEdge.isValid(), false);
}

TEST_F(NamedEdgeTest, addParent){
    namedEdge.addParent(f3);
    EXPECT_ANY_THROW(namedEdge.addParent(f1));

    namedEdge.addParent(f1);
    EXPECT_EQ(namedEdge.numParents(), 1);

    namedEdge.addParent(f2);
    EXPECT_EQ(namedEdge.numParents(), 2);

    EXPECT_ANY_THROW(namedEdge.addParent(f3));
}
