#define BOOST_TEST_MODULE Fixtures
#include <boost/test/unit_test.hpp>
#include <EdgeTracker.h>
#include <MockObjectMaker.h>
#include <stdexcept>

struct Maker{
    mock::MockObjectMaker maker;
    mock::TopoDS_Edge mockOccEdge;
    Trackers::EdgeTracker tracker;
    Maker() :
        mockOccEdge(0),
        tracker(mockOccEdge, std::string("Edge000"))
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
    mock::TopoDS_Face aFace = maker.makeFace();
    aFace.Edges[0] = mockOccEdge;
    BOOST_CHECK_THROW(tracker.addFace(aFace), std::invalid_argument);

}

BOOST_AUTO_TEST_CASE(AddFaceError)
{
    mock::TopoDS_Face aFace = maker.makeFace();
    BOOST_CHECK_THROW(tracker.addFace(aFace), std::invalid_argument);

}

BOOST_AUTO_TEST_SUITE_END()
