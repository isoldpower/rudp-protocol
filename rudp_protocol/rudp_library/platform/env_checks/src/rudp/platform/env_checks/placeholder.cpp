#include <rudp/platform/env_checks/placeholder.hpp>

#include <iostream>


namespace rudp::platform::env_checks {

    bool check_terminal_available() {
        return std::cout.good();
    }

} // namespace rudp::platform::env_checks
