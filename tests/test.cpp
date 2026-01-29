#include <covertcalculus/_.hpp>
#include <cstddef>
#include <iostream>
#include <array>
#include <cstring>
#include <algorithm>

#include <covertcalculus/__/as/CC.hpp>
#include <covertcalculus/memory/__/as/mem.hpp>

CC_FORWARD_ENTRY_FROM_main_TO(main_, std::cout) int main_(CC::mem::span<char*> args) {
    const char *text = "hello";
    const char *text_end = strchr(text, '\0');

    auto printChar = [=](char ch) { std::cout << ch << '\n'; };

    std::for_each(text, text_end, printChar);
    std::cout << std::endl;

    std::array<char, 6> buffer{};
    std::copy(text, text_end + 1, buffer.data());
    std::cout << buffer.data() << '\n';

    return 0;
}