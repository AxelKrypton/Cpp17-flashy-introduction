#if 0

#include <variant>
#include <string>
#include <iostream>

int main()
{
    std::variant<std::string, float> var{
        std::in_place_type<std::string>, 4, 'A'};
    // initializes 1st alternative with std::string{4, 'A'};
    assert(var.index() == 0);
    std::cout << "var=" << std::get<std::string>(var) << '\n';

    std::variant<int, float> v, w;
    v = 42; // v contains int
    int i = std::get<int>(v);
    assert(42 == i); // succeeds
    w = std::get<int>(v);
    w = std::get<0>(v); // same effect as the previous line
    w = v;              // same effect as the previous line

    // Errors:
    //std::get<double>(v); // no double in [int, float]
    //std::get<3>(v);      // valid index values are 0 and 1
}

#endif

#include <variant>
#include <iostream>
            
int main()
{
    std::variant<int, float> v, w;
    v = 42;
    w = v;
                
    // Errors:
    //std::get<double>(v); // no double in [int, float]
    //std::get<3>(v);      // valid index values are 0 and 1

    try {
        std::get<float>(w); // w contains int, not float: will throw
    }
    catch (const std::bad_variant_access& ex) {
        std::cout << ex.what() << '\n';
    }
}
