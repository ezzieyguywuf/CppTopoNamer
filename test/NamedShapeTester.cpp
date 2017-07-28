#include <gtest/gtest.h>
#include <MockObjectMaker.h>
#include <NamedShape.h>

class NamedShapeTest : public testing::Test{
    protected:
        NamedShapeTest()
            : mockEdge(maker.makeEdge()),
              namedShape(mockEdge, "Edge000"){};
        virtual void SetUp()
        {
        }

        MockObjectMaker maker;
        Edge mockEdge;
        NamedShape namedShape;
};

TEST_F(NamedShapeTest, getName){
    EXPECT_EQ(namedShape.getName(), "Edge000");
}

TEST_F(NamedShapeTest, getShape){
    Shape fetchedShape = namedShape.getShape();
    EXPECT_EQ(fetchedShape, mockEdge);
}
