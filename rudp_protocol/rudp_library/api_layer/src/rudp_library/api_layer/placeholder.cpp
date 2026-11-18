#include "rudp_library/api_layer/placeholder.h"

#include <iostream>
#include <string>
#include <rudp_library/transport/placeholder.hpp>


extern "C" void say_hello_n_times(char* name, std::size_t length, std::size_t count) {
    try {
        std::string string_name(name, length);

        return rudp_library::transport::say_hello_n_times(string_name, count);
    } catch (std::exception& exc) {
        std::cerr << "Error occured: " << exc.what() << std::endl;
        return;
    }
}
