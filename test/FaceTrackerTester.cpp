#define BOOST_TEST_MODULE Fixtures
#include <boost/test/unit_test.hpp>
#include <FaceTracker.h>
#include <MockObjectMaker.h>

struct Maker{
    mock::MockObjectMaker maker;
    mock::TopoDS_Face mockOccFace;
    Trackers::FaceTracker faceTracker;
    Maker() :
        mockOccFace(0),
        faceTracker(mockOccFace, std::string("Face000"))
    {} ;
    ~Maker(){};
};

BOOST_FIXTURE_TEST_SUITE(FaceTrackerSuite, Maker)

BOOST_AUTO_TEST_CASE(GetFace)
{
    TopoDS_Face fetchedFace = faceTracker.getFace();
    BOOST_CHECK(fetchedFace.IsEqual(mockOccFace));
}

BOOST_AUTO_TEST_SUITE_END()
