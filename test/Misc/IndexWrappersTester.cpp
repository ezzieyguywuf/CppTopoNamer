#include <gtest/gtest.h>
#include <Managers/Types.h>

TEST(IndexWrappers, CreateInvalid)
{
    Manager::EdgeIndex ind1;
    Manager::FaceIndex ind2;
    EXPECT_EQ(ind1.isValid(), false);
    EXPECT_EQ(ind2.isValid(), false);
}

TEST(IndexWrappers, AssignInvalid)
{
    Manager::EdgeIndex ind1;
    Manager::FaceIndex ind2;
    Manager::EdgeIndex ind3 = ind1;
    Manager::FaceIndex ind4 = ind2;
    EXPECT_EQ(ind3.isValid(), false);
    EXPECT_EQ(ind4.isValid(), false);
}
