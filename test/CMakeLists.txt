#find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include("functions.cmake")

ADD_DEFINITIONS("-DBOOST_TEST_DYN_LINK")

add_subdirectory(googletest)
add_subdirectory(helpers)


#--------------------------------------------------
#   Build production code with mock implementations
#--------------------------------------------------

# syntax: add_mock(ProductionCodeName [lib1 [Lib2 [libn...]]])
# ProductionCodeName MUST be the same as the file to be mocked less .cpp. For example, if the
# production code is in MyShape.cpp, then ProductionCodeName MUST be MyShape.

add_mock(SolidManager_Primitive "Mock_Solid")

#--------------------------------------------------
#   Build tests
#--------------------------------------------------

test_executable("SolidManager_PrimitiveTester" "SolidManager_Primitive")
add_executable(simpleSolidManager "../scratch/simpleSolidManager.cpp")
target_link_libraries(simpleSolidManager "SolidManager_Primitive" "MockObjectMaker")
