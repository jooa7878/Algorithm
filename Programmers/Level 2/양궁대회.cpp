#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer(11);
int mx = 0;

void dfs(int idx, int n, vector<int> info, vector<int> lion)
{    
    if(idx > 11) return;
    if(n == 0 || idx == 10)
    {        
        int lion_score = 0;
        int apeach_score = 0;

        if(idx == 10 && n > 0) 
        {
            for(int i=10; i>=0; i--)
            {
                if(answer[i] == 0)
                {
                    lion[i] = n;
                    break;
                }
            }
        }
        
        for(int i=0; i<info.size(); i++)
        {
            if(lion[i] > info[i]) lion_score += (10 - i);
            else
            {
                 if(info[i] != 0) apeach_score += (10-i);
            }
        }
        
        if(lion_score - apeach_score > mx)
        {
            mx = lion_score - apeach_score;
            answer = lion;
        }
        if( lion_score - apeach_score == mx)
        {
            reverse(answer.begin(), answer.end());
            reverse(lion.begin(), lion.end());
            if (answer < lion) {
                for (int i=0; i<=10; i++) {
                    answer[i] = lion[i];
                }   
            }
            reverse(answer.begin(), answer.end());
        }
        return;
    }
    
    if(n > info[idx])
    {
        vector<int> tmp(lion);
        tmp[idx] = info[idx]+1;
        
        dfs(idx + 1, n - info[idx] - 1, info, tmp);
    }
    
    dfs(idx + 1, n, info, lion);
}

vector<int> solution(int n, vector<int> info) 
{
    vector<int> empty_vector(11);
    dfs(0, n, info, empty_vector);
    
    if(mx == 0 ) return {-1};
    return answer;
}
