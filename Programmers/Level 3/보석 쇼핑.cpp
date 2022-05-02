#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> s;
    unordered_map<string, int> hs;
    int left = 0, right = 0, len = 0;
    
    for(int i=0; i<gems.size(); i++) s.insert(gems[i]);
    
    for(string str : gems)
    {
        hs[str]++;
        if(hs.size() == s.size()) break;
        right++;
    }
    
    len = right - len;
    answer[0] = left +1;
    answer[1] = right + 1;
    
    while(right < gems.size())
    {
        string erased = gems[left];
        hs[erased]--; left++;
        if(hs[erased] == 0)
        {
            right++;
            while(right < gems.size())
            {
                hs[gems[right]]++;
                if(gems[right] == erased) break;
                right++;
            }
            if(right == gems.size()) break;
        }
        
        if(len > right - left)
        {
            len = right - left;
            answer[0] = left + 1;
            answer[1] = right + 1;
        }
    }

    
    return answer;
}
