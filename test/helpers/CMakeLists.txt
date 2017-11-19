include_directories("../include")
include("functions.cmake")

set (OCC_SOURCE_DIR "/home/wolfie/Program/FreeCAD_dev/opencascade-7.1.0")
include_directories(${OCC_SOURCE_DIR}/inc)
link_directories(${OCC_SOURCE_DIR}/Build_Debug/lin64/gcc/libd)

# syntax: make_library(Name [lib1 [lib2[ libn... ]]])
# will add_library for ${Name}.cpp and then target_link_libraries for the libs passed
#make_library(Mock_Shape)
make_library(Mock_Edge)
make_library(Mock_Face "Mock_Edge")
make_library(Mock_Solid "Mock_Face")
make_library(MockObjectMaker "Mock_Solid")
make_library(OccObjectMaker "OccSolid" TKBRep TKPrim TKernel TKGeomAlgo TKTopAlgo TKMath TKBO TKG3d TKGeomBase TKCAF TKLCAF TKBool TKFillet)
#make_library(NamedShape_MockImpl "INamedShape")

# these are not real unit tests. Rather, they are small executables that test the various
# mock objects made which are used in unit tests.

#make_test(ShapeTester "Mock_Shape")
make_test(EdgeTester "Mock_Edge")
make_test(FaceTester "Mock_Edge" "Mock_Face")
make_test(SolidTester "Mock_Solid")
make_test(MockObjectMakerTester "MockObjectMaker")
