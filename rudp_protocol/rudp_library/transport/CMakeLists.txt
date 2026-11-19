add_library(rudp_transport STATIC src/rudp/transport/placeholder.cpp)

target_include_directories(rudp_transport PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(rudp_transport
    PRIVATE cxx_setup
    PRIVATE rudp_io
    PRIVATE rudp_env_checks
    PRIVATE rudp_core)
