function(add_mock Name)
    add_library(${Name} "${PROJECT_SOURCE_DIR}/src/${Name}.cpp")
    # This ensures that our mocked headers are found before the production headers
    target_include_directories(${Name} BEFORE PUBLIC "${PROJECT_SOURCE_DIR}/test/include")
    target_link_libraries(${Name} ${ARGN})
endfunction(add_mock)

function(test_executable TestName)
    message("currently, ARGN_ = ${ARGN}")
    add_executable(${TestName} "${TestName}.cpp")
    target_link_libraries(${TestName}
        "gtest_main"
        "MockObjectMaker"
        ${ARGN})
    target_include_directories(${TestName} BEFORE PUBLIC
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURE_DIR}
        include)
    add_test(NAME "Test_${TestName}" COMMAND $<TARGET_FILE:${TestName}>)
endfunction(test_executable)
