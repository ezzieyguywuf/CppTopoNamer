#define BOOST_TEST_MODULE Fixtures
#include <boost/test/unit_test.hpp>
#include <OccObjectTrackers.h>
#include <MockObjectMaker.h>

struct Maker{
    MockObjectMaker maker;
    Trackers::OccObjectTracker tracker;
    Maker() :
        tracker("Object000")
    {} ;
    ~Maker(){};
};

BOOST_FIXTURE_TEST_SUITE(OccObjectTracker, Maker)

BOOST_AUTO_TEST_CASE(GetName)
{
    std::string fetchedName = tracker.getName();
    BOOST_CHECK_EQUAL(fetchedName, "Object000");
}

BOOST_AUTO_TEST_SUITE_END()
