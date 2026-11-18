add_executable(test_linkage main.cpp)
target_link_libraries(test_linkage
    PRIVATE rudp_capi
    PRIVATE cxx_setup)

