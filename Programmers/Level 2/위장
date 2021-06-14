#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {    
    
    unordered_map<string, int> h;
    
    for(auto& cloth : clothes)
    {
        h[cloth[1]]++;
    }
    
    int count = 1;
    
    for(auto& cloth : h)
    {
        count *= ( cloth.second + 1);
    }
    
    return count - 1;
}
