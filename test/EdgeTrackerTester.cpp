#define BOOST_TEST_MODULE Fixtures
#include <boost/test/unit_test.hpp>
#include <EdgeTracker.h>
#include <FaceTracker.h>
#include <MockObjectMaker.h>
#include <stdexcept>

struct Maker{
    mock::MockObjectMaker maker;
    mock::TopoDS_Edge mockOccEdge;
    mock::TopoDS_Face mockOccFace;
    Trackers::EdgeTracker edgeTracker;
    Trackers::FaceTracker faceTracker;
    Maker() :
        mockOccEdge(0),
        mockOccFace(0),
        edgeTracker(mockOccEdge, std::string("Edge000")),
        faceTracker(mockOccFace, std::string("Face000"))
    {} ;
    ~Maker(){};
};

BOOST_FIXTURE_TEST_SUITE(EdgeTrackerSuite, Maker)

BOOST_AUTO_TEST_CASE(GetEdge)
{
    TopoDS_Edge fetchedEdge = edgeTracker.getEdge();
    BOOST_CHECK(fetchedEdge.IsEqual(mockOccEdge));
}

//BOOST_AUTO_TEST_CASE(AddFace_NoEdgeError)
//{
    //mock::TopoDS_Face aFace = maker.makeFace();
    //BOOST_CHECK_THROW(edgeTracker.addFace(faceTracker), std::invalid_argument);

//}

//BOOST_AUTO_TEST_CASE(AddFace)
//{
    //mock::TopoDS_Face aFace = maker.makeFace();
    //aFace.Edges[0] = mockOccEdge;
    //edgeTracker.addFace(aFace, "Face000");
    //BOOST_CHECK_EQUAL(edgeTracker.isValid(), false);
//}

BOOST_AUTO_TEST_SUITE_END()
