#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    pair<int, int> max_pair = {0, 0};
    
    for(int i=0; i<sizes.size(); i++)
    {
        int width = sizes[i][0] > sizes[i][1] ? sizes[i][0] : sizes[i][1];
        int height = sizes[i][0] > sizes[i][1] ? sizes[i][1] : sizes[i][0];
        
        if(width > max_pair.first) max_pair.first = width;
        if(height > max_pair.second) max_pair.second = height;

    }
    return max_pair.first * max_pair.second;
}
