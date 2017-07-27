#define BOOST_TEST_MODULE Fixtures
#include <boost/test/unit_test.hpp>
#include <MockObjectMaker.h>
#include <NamedShape.h>

struct Maker{
    MockObjectMaker maker;
    Edge mockEdge;
    Maker() : mockEdge(maker.makeEdge()) {} ;
    ~Maker(){};
};

BOOST_FIXTURE_TEST_SUITE(NamedShapeSuite, Maker)

BOOST_AUTO_TEST_CASE(addName)
{
    NamedShape myShape(mockEdge, "Edge000");
    std::string name = myShape.getName();
    BOOST_CHECK_EQUAL(name, "Edge000");
}

    //Face fetchedFace = faceTracker.getFace();
    //BOOST_CHECK_EQUAL(fetchedFace, mockFace);
BOOST_AUTO_TEST_SUITE_END()
