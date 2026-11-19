add_library(rudp_env_checks STATIC src/rudp/platform/env_checks/placeholder.cpp)

target_include_directories(rudp_env_checks PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(rudp_env_checks
    PRIVATE cxx_setup)
