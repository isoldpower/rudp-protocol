add_library(rudp_core STATIC src/rudp_library/core/placeholder.cpp)

target_include_directories(rudp_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(rudp_core PRIVATE cxx_setup)
