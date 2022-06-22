#include <algorithm>
#include <vector>
#include <execution>
            
int main()
{
    int a[] = {0,1};
    std::vector<int> v;
    std::for_each(std::execution::par,
                  std::begin(a), std::end(a),
                  [&](int i){
                      v.push_back(i*2+1); // Error: data race
                  });
                
    std::vector<int> longVector;
    // Find element using parallel execution policy
    auto result = std::find(std::execution::par,
                            std::begin(longVector),
                            std::end(longVector),
                            2);
}
