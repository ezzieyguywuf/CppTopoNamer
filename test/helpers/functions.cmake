function(make_library Name)
    add_library(${Name} "${Name}.cpp")
    target_link_libraries(${Name} ${ARGN})
endfunction(make_library)

function(make_test Name)
    add_executable(${Name} "${Name}.cpp")
    target_link_libraries(${Name} ${ARGN})
endfunction(make_test)
