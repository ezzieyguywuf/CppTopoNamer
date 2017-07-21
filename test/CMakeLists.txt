find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories("include")

ADD_DEFINITIONS("-DBOOST_TEST_DYN_LINK")
add_subdirectory(helpers)

set (TESTS
    BaseTrackerTester
    EdgeTrackerTester
    )

set (LIBS
    "Mock_TopoDS_Shape"
    "Mock_TopoDS_Edge"
    "Mock_TopoDS_Face"
    "MockObjectMaker"
    "EdgeTracker"
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    "TKBRep"
    "TKernel"
    "TKMath"
    )

foreach (testName ${TESTS})
    add_executable(${testName} "${testName}.cpp")
    target_link_libraries(${testName} ${LIBS})
    add_test("Test_${testName}" ${testName})
endforeach(testName ${TESTS})

#add_executable(MockObjectMaker "MockObjectMaker.cpp")
#target_link_libraries(MockObjectMaker
    #Mock_TopoDS_Shape
    #Mock_TopoDS_Edge
    #Mock_TopoDS_Face
    #)
