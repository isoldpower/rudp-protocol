#include "rudp_library/core/placeholder.hpp"

#include <sstream>


namespace rudp_library::core {

    std::string salute_from_core(const std::string& name) {
        std::ostringstream string_stream;
        string_stream << "Hello, " << name << " from library core\n";

        return string_stream.str();
    }

} // namespace rudp_library::core {
