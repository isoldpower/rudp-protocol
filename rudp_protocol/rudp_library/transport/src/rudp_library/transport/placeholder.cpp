#include "rudp_library/transport/placeholder.hpp"

#include <iostream>
#include <rudp_library/core/placeholder.hpp>
#include <rudp_library/platform/io/placeholder.hpp>
#include <rudp_library/platform/env_checks/placeholder.hpp>


namespace rudp_library::transport {

    void say_hello_n_times(const std::string& name, std::size_t count) {
        if (!platform::env_checks::check_terminal_available()) {
            return;
        }

        for (std::size_t i = 0; i < count; ++i) {
            std::ostream& console_stream = platform::io::get_console_stream();
            console_stream << core::salute_from_core(name);
        }
    }

} // namespace rudp_library::transport

