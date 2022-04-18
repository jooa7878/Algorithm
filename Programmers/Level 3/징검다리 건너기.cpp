#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool check(int mid, int k, vector<int> stones)
{
    int cnt = 0;
    for(int i=0; i<stones.size(); i++)
    {
        if(mid >= stones[i]) cnt++;
        else cnt = 0;
        
        if(cnt >= k) return true;
    }
    
    return false;
}

int solution(vector<int> stones, int k) 
{                                        
    int answer = 0;
    int left = 1, right = *max_element(stones.begin(), stones.end());
    
    while(left <= right)
    {
        int mid = (left + right) / 2;   
        if(check(mid, k, stones))
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    answer = left;
    
    return answer;
}
