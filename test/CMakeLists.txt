find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

ADD_DEFINITIONS("-DBOOST_TEST_DYN_LINK")

add_subdirectory(googletest)
add_subdirectory(helpers)

set (TESTS
    #BaseTrackerTester
    #FaceTrackerTester
    #EdgeTrackerTester
    NamedShapeTester
    #NamedEdgeTester
    )

set (LIBS
    #"gtest"
    "gtest_main"
    "MockObjectMaker"
    "NamedShape_MockImpl"
    #"FaceTracker"
    #${Boost_FILESYSTEM_LIBRARY}
    #${Boost_SYSTEM_LIBRARY}
    #${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )


add_library(INamedShape "../src/INamedShape.cpp")
target_include_directories(INamedShape BEFORE PUBLIC "./include")
target_link_libraries(INamedShape "Mock_Shape")
foreach (testName ${TESTS})
    add_executable(${testName} "${testName}.cpp")
    target_link_libraries(${testName} ${LIBS})
    target_include_directories(${testName} BEFORE PUBLIC
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURE_DIR})
    add_test("Test_${testName}" ${testName})
endforeach(testName ${TESTS})
