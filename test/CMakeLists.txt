find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories("include")

ADD_DEFINITIONS("-DBOOST_TEST_DYN_LINK")
add_subdirectory(helpers)

set (TESTS
    #BaseTrackerTester
    FaceTrackerTester
    #EdgeTrackerTester
    )

set (LIBS
    "MockObjectMaker"
    "FaceTracker"
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )

foreach (testName ${TESTS})
    add_executable(${testName} "${testName}.cpp")
    target_link_libraries(${testName} ${LIBS})
    add_test("Test_${testName}" ${testName})
endforeach(testName ${TESTS})

#add_executable(MockObjectMaker "MockObjectMaker.cpp")
#target_link_libraries(MockObjectMaker
    #Mock_Shape
    #Mock_Edge
    #Mock_Face
    #)
