#include <iostream>
#include <string>
#include <cstddef>
#include <rudp/api_layer/placeholder.h>


constexpr std::size_t REPEAT_COUNT = 4;

auto main() -> int {
    char name[] = "Nikita";
    say_hello_n_times(name, std::strlen(name), REPEAT_COUNT);

	return 0;
}
