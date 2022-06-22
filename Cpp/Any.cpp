#include <any>
#include <iostream>
            
int main()
{
    std::cout << std::boolalpha;
                
    std::any a = 1;
    std::cout << '[' << std::any_cast<int>(a) << ", ";
    a = 3.14;
    std::cout << std::any_cast<double>(a) << ", ";
    a = true;
    std::cout << std::any_cast<bool>(a) << "]\n";
                
    try
    {
        std::cout << std::any_cast<float>(a) << '\n';
    }
    catch (const std::bad_any_cast& e)
    {
        std::cout << e.what() << '\n';
    }
}
