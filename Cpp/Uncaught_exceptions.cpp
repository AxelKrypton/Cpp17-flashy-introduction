// Taken from https://stackoverflow.com/a/49503194/14967071
#include <exception>
#include <iostream>
#include <string>

class T {
public:

    ~T() noexcept(false) {
#if __cplusplus >= 201703L
        // C++17 - correct check
        std::cout << "T.uncaught_exceptions_ = " << uncaught_exceptions_ << "\n";
        if (std::uncaught_exceptions() == uncaught_exceptions_) {
#else
        // Older C++ - incorrect check
        std::cout << "std::uncaught_exception() = " << std::boolalpha << std::uncaught_exception() << "\n";
        if (!std::uncaught_exception()) {
#endif
            throw (std::string{__PRETTY_FUNCTION__} + " doing real work");
        }
        else
        {
            std::cerr << __PRETTY_FUNCTION__ << " cowardly quitting\n";
        }
    }

private:
#if __cplusplus >= 201703L
    const int uncaught_exceptions_ {std::uncaught_exceptions()};
#endif
};

class U
{
public:

    ~U(){
        try
        {
            T t;
        }
        catch (const std::string &e)
        {
            std::cerr << __PRETTY_FUNCTION__ << " caught: " << e << '\n';
        }
    }
};

int main() {
    try
    {
        U u;
        throw (std::string{__PRETTY_FUNCTION__} + " threw an exception");
    }
    catch (const std::string &e)
    {
        std::cerr << __PRETTY_FUNCTION__ << " caught: " << e << '\n';
    }
    return 0;
}
