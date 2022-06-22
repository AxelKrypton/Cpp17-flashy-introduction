#include <iostream>
#include <string>
#include <string_view>

int main(int argc, char *argv[]){
    std::string str {"   trim me"};
    std::string_view v {str};
    v.remove_prefix(std::min(v.find_first_not_of(" "), v.size()));
    std::cout << '_' << str << "_\t_" << v << "_\n";

    // Wide strings.
    std::wstring_view wsv {L"baz"};
    // Character arrays.
    char array[3] = {'b', 'a', 'r'};
    std::string_view array_v(array, std::size(array));
    // Very bad idea -> view is NOT OWNING!
    using namespace std::literals;
    auto getSV = [](){
        std::string x = "local";
        return std::string_view{x};
    };
    std::string_view bad = getSV();
    std::cout << bad << '\n'; //UB
}
