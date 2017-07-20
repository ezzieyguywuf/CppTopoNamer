find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories("include")

ADD_DEFINITIONS("-DBOOST_TEST_DYN_LINK")

add_executable(OccObjectTrackerTester "OccObjectTrackerTester.cpp" "MockObjectMaker.cpp")
target_link_libraries(OccObjectTrackerTester
    "OccObjectTrackers"
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    "TKBRep"
    "TKernel"
    "TKMath"
    )
