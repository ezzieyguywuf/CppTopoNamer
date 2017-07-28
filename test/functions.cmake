function(add_mock Name)
    add_library(${Name} "../src/${Name}.cpp")
    # This ensures that our mocked headers are found before the production headers
    target_include_directories(${Name} BEFORE PUBLIC "include")
    target_link_libraries(${Name} ${ARGN})
endfunction(add_mock)

function(test_executable TestName)
    add_executable(${TestName} "${TestName}.cpp")
    target_link_libraries(${TestName}
        "gtest_main"
        "MockObjectMaker"
        ${ARGN})
    target_include_directories(${TestName} BEFORE PUBLIC
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURE_DIR})
    add_test("Test_${TestName}" ${TestName})
endfunction(test_executable)
