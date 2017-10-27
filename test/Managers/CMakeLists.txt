include("functions.cmake")

#--------------------------------------------------
#   Build production code with mock implementations
#--------------------------------------------------

# syntax: add_mock(ProductionCodeName [lib1 [Lib2 [libn...]]])
# ProductionCodeName MUST be the same as the file to be mocked less .cpp. For example, if the
# production code is in MyShape.cpp, then ProductionCodeName MUST be MyShape.

add_mock(PrimitiveSolid "Mock_Solid")

#--------------------------------------------------
#   Build tests
#--------------------------------------------------

test_executable("PrimitiveSolidTester" "Mock_Solid" "PrimitiveSolid")

# various scratch test programs
add_executable(simpleSolidManager "${PROJECT_SOURCE_DIR}/scratch/simpleSolidManager.cpp")
target_link_libraries(simpleSolidManager "PrimitiveSolid" "MockObjectMaker")

add_executable(simpleFaceTester "${PROJECT_SOURCE_DIR}/scratch/simpleFaceTester.cpp")
target_link_libraries(simpleFaceTester "Mock_Face")

