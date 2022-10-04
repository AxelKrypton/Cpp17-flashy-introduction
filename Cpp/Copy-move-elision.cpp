#include <iostream>

#if 0

struct C {
    C() { std::cout << "Default ctor called.\n"; }
    C(const C&) { std::cout << "Copy ctor called.\n"; }
    C(C&&) { std::cout << "Move ctor called.\n"; }
};
 
C foo() {
    return C(); // Guaranteed to perform copy elision
}
C bar() {
    C c;
    return c; //Maybe performs copy elision
}
 
int main() {
    C obj = foo(); //Move constructor isn't called
    std::cout << "-------\n";
    C obj2 = bar();
}

#else

struct C {
    C() { std::cout << "Default ctor called.\n"; }
    C(const C&) = delete;
    C(C&&) = delete;
};
 
C foo() {
    return C(); // Guaranteed to perform copy elision
}
/*
 * Uncommenting results in compilation error, since
 * copy/move elision is not guaranteed here!
 */
 C bar() {
     C c;
     return c; //Maybe performs copy elision
 }
 
int main() {
    C obj = foo(); //Move constructor isn't called
}

#endif
