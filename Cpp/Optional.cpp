#include <iostream>
#include <optional>

#if 0

#include <sstream>

std::optional<int> to_int(const std::string& s ) {
    std::optional<int> oi{}; int i;
    if( std::stringstream stm(s); stm >> i )
        if( stm.get() == std::char_traits<char>::eof() )
            oi = i; return oi;
}

int main()
{
    auto number = to_int("-42");
    std::cout << *number << '\n';
}

#else

#include <string_view>

auto slice(std::string_view str,
           std::optional<int> start,
           std::optional<int> end)
{
    auto s = start.value_or(0);
    auto e = end.value_or(str.size());
    return str.substr(s, e-s);
}

int main()
{
    std::cout << slice("Hello world!", 6, std::nullopt) << '\n';
    std::cout << slice("Hello world!", std::nullopt, 5) << '\n';
}

#endif
