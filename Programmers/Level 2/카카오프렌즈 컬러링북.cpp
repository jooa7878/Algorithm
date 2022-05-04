#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[101][101];

int bfs(int y, int x, vector<vector<int>> picture, int num)
{
    queue<pair<int, int>> q;
    
    q.push({y, x});
    
    int cnt = 0;
    
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        cnt++;
        
        q.pop();

        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if( nx >= 0 && ny >= 0 && nx < picture[0].size() && ny < picture.size() && !visited[ny][nx] && picture[ny][nx] == num)
            {
                
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
    
    
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            visited[i][j] = false;            
        }
    }
    
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j] && picture[i][j] != 0)
            {
        
                visited[i][j] = true;
                answer[0]++;
                
                int res = bfs(i, j, picture, picture[i][j]);
                answer[1] = max(res, answer[1]);   
            }
        }
    }
    
    return answer;
}
