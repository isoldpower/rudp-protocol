#include <rudp/platform/io/placeholder.hpp>


namespace rudp::platform::io {

    std::ostream& get_console_stream() {
        return std::cout;
    }

} // namespace rudp::platform::io
