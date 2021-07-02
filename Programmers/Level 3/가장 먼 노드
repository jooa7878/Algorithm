#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool arr[20001][20001];
bool visited[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max = 0;
    vector<pair<int,int>> vec;    
    queue<pair<int, int>> q;
    
    for(int i=0; i<edge.size(); i++)
    {
        arr[edge[i][0]][edge[i][1]] = 1;
        arr[edge[i][1]][edge[i][0]] = 1;
    }
    
    q.push(make_pair(0,1));
    visited[1] = 1;
    
    while(!q.empty())
    {
        int distance = q.front().first;
        int node = q.front().second;
        
        q.pop();
        
        if( distance > max ) max = distance;
        
        for(int i=1; i<=n; i++)
        {
            if(arr[node][i] && !visited[i])
            {
                q.push(make_pair(distance+1, i));
                vec.push_back(make_pair(distance+1, i));
                visited[i] = true;
            }
        }
    }
    
    sort(vec.begin(), vec.end());
    
    for(int i=vec.size()-1; i>=0; i--)
    {
        if(vec[i].first == max) answer++;
        else break;
    }
    
    return answer;
}
