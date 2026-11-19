#include <rudp/core/placeholder.hpp>

#include <sstream>


namespace rudp::core {

    std::string salute_from_core(const std::string& name) {
        std::ostringstream string_stream;
        string_stream << "Hello, " << name << " from library core\n";

        return string_stream.str();
    }

} // namespace rudp::core {
