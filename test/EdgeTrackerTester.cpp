#define BOOST_TEST_MODULE Fixtures
#include <boost/test/unit_test.hpp>
#include <EdgeTracker.h>
#include <FaceTracker.h>
#include <MockObjectMaker.h>
#include <stdexcept>

struct Maker{
    mock::MockObjectMaker maker;
    mock::TopoDS_Edge mockOccEdge;
    Trackers::EdgeTracker edgeTracker;
    Maker() :
        mockOccEdge(0),
        edgeTracker(mockOccEdge, std::string("Edge000"))
    {} ;
    ~Maker(){};
};

BOOST_FIXTURE_TEST_SUITE(EdgeTrackerSuite, Maker)

BOOST_AUTO_TEST_CASE(GetEdge)
{
    TopoDS_Edge fetchedEdge = edgeTracker.getEdge();
    BOOST_CHECK(fetchedEdge.IsEqual(mockOccEdge));
}

BOOST_AUTO_TEST_CASE(AddFace_NoEdgeError)
{
    mock::TopoDS_Face aFace = maker.makeFace();
    Trackers::FaceTracker myTracker(aFace, "Face000");
    BOOST_CHECK_THROW(edgeTracker.addFace(myTracker), std::invalid_argument);

}

BOOST_AUTO_TEST_CASE(AddFace)
{
    mock::TopoDS_Face aFace = maker.makeFace();
    aFace.Edges[0] = mockOccEdge;
    Trackers::FaceTracker myTracker(aFace, "Face000");
    edgeTracker.addFace(myTracker);
    BOOST_CHECK_EQUAL(edgeTracker.isValid(), false);
}

BOOST_AUTO_TEST_SUITE_END()
