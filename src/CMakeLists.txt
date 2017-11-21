add_library(OccEdge SHARED "OccEdge.cpp")
target_link_libraries(OccEdge "TKBRep" "TKPrim" "TKMath")

add_library(OccFace SHARED "OccFace.cpp")
target_link_libraries(OccFace "OccEdge")

add_library(OccSolid SHARED "OccSolid.cpp")
target_link_libraries(OccSolid "OccFace")

add_library(PrimitiveSolidManager SHARED "PrimitiveSolid.cpp")
target_link_libraries(PrimitiveSolidManager "OccSolid")
