#include <rudp_library/platform/io/placeholder.hpp>


namespace rudp_library::platform::io {

    std::ostream& get_console_stream() {
        return std::cout;
    }

} // namespace rudp_library::platform::io
