#include <iostream>
#include <string_view>

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

using namespace std::string_literals;

int main(){
    //auto x1 {1, 2, 3}; // error: not a single element
    auto x1 = {1};
    auto x2 = {1, 2, 3};
    auto x3 {3u};
    auto x4 {3.0f};
    auto x5 {"abc"s};
    // auto x6 {{'a', 'b', 'c'}}; // https://stackoverflow.com/a/59471865/14967071
    std::cout << type_name<decltype(x1)>() << "\n"
              << type_name<decltype(x2)>() << "\n"
              << type_name<decltype(x3)>() << "\n"
              << type_name<decltype(x4)>() << "\n"
              << type_name<decltype(x5)>() << "\n";
}
