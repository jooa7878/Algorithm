#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> vec[101];
bool visited[101];
int arr[101][101];
int cnt;

void dfs(int pos, int from, int to){
    
    visited[pos] = true;
    cnt++;
    for(int i=0; i<vec[pos].size(); i++)
    {
        int next = vec[pos][i];
        if(!visited[next] )
        {
            if(pos == from && next == to || pos == to && next == from) continue;
            dfs(next, from, to);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for(int i=0; i<wires.size(); i++)
    {
        int from = wires[i][0], to = wires[i][1];
        
        vec[from].push_back(to);
        vec[to].push_back(from);
    }
    
    for(int i=0; i<wires.size(); i++)
    {
        int from = wires[i][0], to = wires[i][1];
        int a = 0, b = 0;
        for(int j=1; j<=n; j++)
        {
            if(!visited[j])
            {   
                dfs(j, from, to);
                if(a == 0) a = cnt;
                else b = cnt;
                cnt = 0;
            }
        }
        answer = min(answer, abs(a-b));
        for(int j=1; j<=n; j++) visited[j] = false;
    }
    
    return answer;
}
