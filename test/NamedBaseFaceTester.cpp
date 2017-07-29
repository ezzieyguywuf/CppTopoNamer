#include <gtest/gtest.h>
#include <MockObjectMaker.h>
#include <NamedBaseFace.h>

class NamedFaceTest : public testing::Test{
    protected:
        NamedFaceTest()
            : mockFace(maker.makeFace()),
              namedFace(mockFace, "Face000")
        {};
        virtual void SetUp()
        {
        }

        MockObjectMaker maker;
        Face mockFace;
        NamedBaseFace namedFace;
};

TEST_F(NamedFaceTest, getShape){
    EXPECT_EQ(namedFace.getShape(), mockFace);
}

TEST_F(NamedFaceTest, getName){
    EXPECT_EQ(namedFace.getName(), "Face000");
}
