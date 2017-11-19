#add_library(BaseTracker "BaseTracker.cpp")
#add_library(FaceTracker SHARED "FaceTracker.cpp")
#add_library(EdgeTracker SHARED "EdgeTracker.cpp")
#target_link_libraries(EdgeTracker "BaseTracker"  "TKBRep" "TKPrim" "TKMath")

#add_library(NamedShape SHARED "NamedShape.cpp")

add_library(OccEdge SHARED "OccEdge.cpp")
target_link_libraries(OccEdge "TKBRep" "TKPrim" "TKMath")

add_library(OccFace SHARED "OccFace.cpp")
target_link_libraries(OccFace "OccEdge")

add_library(OccSolid SHARED "OccSolid.cpp")
target_link_libraries(OccSolid "OccFace")

add_library(PrimitiveSolidManager SHARED "PrimitiveSolid.cpp")
target_link_libraries(PrimitiveSolidManager "OccSolid")
