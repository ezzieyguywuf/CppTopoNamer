find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories("include")

ADD_DEFINITIONS("-DBOOST_TEST_DYN_LINK")

set (TESTS
    OccObjectTrackerTester
    EdgeTrackerTester
    )

set (LIBS
    "OccObjectTrackers"
    "MockObjectMaker"
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    "TKBRep"
    "TKernel"
    "TKMath"
    )

add_library(MockObjectMaker "MockObjectMaker.cpp")

foreach (testName ${TESTS})
    add_executable(${testName} "${testName}.cpp")
    target_link_libraries(${testName} ${LIBS})
    add_test("Test_${testName}" ${testName})
endforeach(testName ${TESTS})
