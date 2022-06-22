#include <iostream>

void f()
{
    if constexpr(false) {
        int i = 0;
        //int *p = i; // Error even though discarded 
    }
}

template <typename T>
constexpr bool isIntegral() {
    if constexpr (std::is_integral<T>::value) {
        return true;
    } else {
        return false;
    }
}

struct S {};

int main(){
    static_assert(isIntegral<int>() == true);
    static_assert(isIntegral<char>() == true);
    static_assert(isIntegral<double>() == false);
    static_assert(isIntegral<S>() == true);
}
