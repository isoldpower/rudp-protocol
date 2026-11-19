#include <rudp/transport/placeholder.hpp>

#include <iostream>
#include <rudp/core/placeholder.hpp>
#include <rudp/platform/io/placeholder.hpp>
#include <rudp/platform/env_checks/placeholder.hpp>


namespace rudp::transport {

    void say_hello_n_times(const std::string& name, std::size_t count) {
        if (!platform::env_checks::check_terminal_available()) {
            return;
        }

        for (std::size_t i = 0; i < count; ++i) {
            std::ostream& console_stream = platform::io::get_console_stream();
            console_stream << core::salute_from_core(name);
        }
    }

} // namespace rudp::transport

