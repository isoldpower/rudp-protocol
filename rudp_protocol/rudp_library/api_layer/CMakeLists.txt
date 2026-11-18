add_library(rudp_capi SHARED src/rudp_library/api_layer/placeholder.cpp)

target_include_directories(rudp_capi PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(rudp_capi
    PRIVATE rudp_transport
    PRIVATE cxx_setup)
