#include <iostream>
#include <string>
#include <vector>

using namespace std;

int length = 0;
int ans[8];
bool visited[8];
int answer = 0;

void dfs(int depth, int k, vector<vector<int>> dungeons)
{
    
    if(depth == length)
    {
        int cnt = 0;
     
        for(int i=0; i<length; i++)
        {
            if(k >= dungeons[ans[i]][0])
            {
                cnt++;
                k -= dungeons[ans[i]][1];
            }
            else break;
        }
        
        if(cnt > answer) answer = cnt;
    }
    
    for(int i=0; i<length; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            ans[i] = depth;
            dfs(depth+1, k, dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    length = dungeons.size();
    
    dfs(0, k, dungeons);
    
    return answer;
}
