add_library(rudp_io STATIC src/rudp/platform/io/placeholder.cpp)

target_include_directories(rudp_io PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(rudp_io 
    PRIVATE cxx_setup)
