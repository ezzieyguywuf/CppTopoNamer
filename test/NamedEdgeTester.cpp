#include <gtest/gtest.h>
#include <MockObjectMaker.h>
#include <NamedEdge.h>

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
        NamedEdge namedEdge;
};

TEST_F(NamedEdgeTest, isValid){
    EXPECT_EQ(namedEdge.isValid(), false);
}
