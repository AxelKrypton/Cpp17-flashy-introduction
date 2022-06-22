#include <iostream>
#include <map>
#include <iomanip>

int main(){
    std::map<int, std::string> m;
    if (auto it = m.find(10); it != m.end())
        std::cout << it->second.size();
    else
        std::cout << std::boolalpha << (it==m.end()) << "\n";
}
int main(int argc, char *argv[]){
    
}
