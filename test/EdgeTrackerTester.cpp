#define BOOST_TEST_MODULE Fixtures
#include <boost/test/unit_test.hpp>
#include <OccObjectTrackers.h>
#include <MockObjectMaker.h>
#include <stdexcept>

struct Maker{
    MockObjectMaker maker;
    FakeOCCEdge mockOccEdge;
    Trackers::EdgeTracker tracker;
    Maker() :
        mockOccEdge(0),
        tracker(mockOccEdge, "Edge000")
    {} ;
    ~Maker(){};
};

BOOST_FIXTURE_TEST_SUITE(EdgeTracker, Maker)

BOOST_AUTO_TEST_CASE(GetEdge)
{
    TopoDS_Edge fetchedEdge = tracker.getEdge();
    BOOST_CHECK(fetchedEdge.IsEqual(mockOccEdge));
}

BOOST_AUTO_TEST_CASE(AddFace)
{
    FakeOCCFace aFace = maker.OCCFace();
    aFace.Edges[0] = mockOccEdge;
    BOOST_CHECK_THROW(tracker.addFace(aFace), std::invalid_argument);

}

BOOST_AUTO_TEST_CASE(AddFaceError)
{
    FakeOCCFace aFace = maker.OCCFace();
    BOOST_CHECK_THROW(tracker.addFace(aFace), std::invalid_argument);

}

BOOST_AUTO_TEST_SUITE_END()
