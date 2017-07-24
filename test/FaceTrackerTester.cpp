#define BOOST_TEST_MODULE Fixtures
#include <boost/test/unit_test.hpp>
#include <FaceTracker.h>
#include <MockObjectMaker.h>

struct Maker{
    MockObjectMaker maker;
    mock::Face mockFace;
    Trackers::FaceTracker faceTracker;
    Maker() :
        mockFace(maker.makeFace()),
        faceTracker(mockFace, mockFace.getName())
    {} ;
    ~Maker(){};
};

BOOST_FIXTURE_TEST_SUITE(FaceTrackerSuite, Maker)

BOOST_AUTO_TEST_CASE(GetFace)
{
    Face fetchedFace = faceTracker.getFace();
    BOOST_CHECK_EQUAL(fetchedFace, mockFace);
}

BOOST_AUTO_TEST_SUITE_END()
