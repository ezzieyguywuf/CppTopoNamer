find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

ADD_DEFINITIONS("-DBOOST_TEST_DYN_LINK")
add_subdirectory(helpers)

set (TESTS
    #BaseTrackerTester
    #FaceTrackerTester
    #EdgeTrackerTester
    NamedShapeTester
    )

set (LIBS
    "MockObjectMaker"
    "NamedShape"
    #"FaceTracker"
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )

add_library(NamedShape "../src/NamedShape.cpp")
target_include_directories(NamedShape BEFORE PUBLIC "./include")
target_link_libraries(NamedShape "Mock_Shape")
foreach (testName ${TESTS})
    add_executable(${testName} "${testName}.cpp")
    target_link_libraries(${testName} ${LIBS})
    add_test("Test_${testName}" ${testName})
endforeach(testName ${TESTS})
