add_executable(test_complex test_complex.cpp)

add_executable(test_rational test_rational.cpp)

add_executable(test_dynarr test_dynarr.cpp)

add_executable(test_stackarr test_stackarr.cpp)
add_executable(test_stackarrt test_stackarrt.cpp)

add_executable(test_stack_list test_stack_list.cpp)

add_executable(test_queue_list test_queue_lst.cpp)

target_link_libraries(test_complex complex)
target_link_libraries(test_rational rational)
#target_link_libraries(test_dynarr dynarr)
target_link_libraries(test_stackarr stackarr)
target_link_libraries(test_stackarrt stackarrt)
target_link_libraries(test_stack_list stacklst)
#target_link_libraries(test_queue_list queuelst)
#target_link_libraries(test_queue_arr queuearr)