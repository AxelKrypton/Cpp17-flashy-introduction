#include <iostream>
#include <utility>
#include <string_view>
#include <unordered_map>

template <typename T>
constexpr auto type_name() {
    std::string_view name, prefix, suffix;
#ifdef __clang__
    name = __PRETTY_FUNCTION__;
    prefix = "auto type_name() [T = ";
    suffix = "]";
#elif defined(__GNUC__)
    name = __PRETTY_FUNCTION__;
    prefix = "constexpr auto type_name() [with T = ";
    suffix = "]";
#elif defined(_MSC_VER)
    name = __FUNCSIG__;
    prefix = "auto __cdecl type_name<";
    suffix = ">(void)";
#endif
    name.remove_prefix(prefix.size());
    name.remove_suffix(suffix.size());
    return name;
}

auto get_mix() {
    return std::make_tuple(42U, 1, 3.14, 'b', "Hello");
}

auto get_ints() {
    return std::make_pair(42, 1);
}

int main(){
    auto [u, n, pi, letter, label] = get_mix();
    const auto& [n1, n2] = get_ints();
    std::cout << "[" << type_name<decltype(u)>() << ", "
              << type_name<decltype(n)>() << ", "
              << type_name<decltype(pi)>() << ", "
              << type_name<decltype(letter)>() << ", "
              << type_name<decltype(label)>() << "]\n";

    std::unordered_map<std::string, int> mapping {
        {"a", 1},
        {"b", 2},
        {"c", 3}
    };
                
    // Destructure by reference.
    for (const auto& [key, value] : mapping) {
        std::cout << key << " -> " << value << "\n";
    }
}
