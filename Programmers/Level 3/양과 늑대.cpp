#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<int> adj[18];
bool visited[200];

void dfs(int node, int sheep, int wolf, vector<int> route, vector<int> info)
{
  sheep += info[node] == 0 ? 1 : 0;
  wolf += info[node];

  if (wolf >= sheep) return;

  if (sheep > answer) answer = sheep;

  for (int i = 0; i < route.size(); i++)
  {
    for (int j = 0; j < adj[route[i]].size(); j++)
    {
      int next = adj[route[i]][j];

      if (!visited[next])
      {
        vector<int> tmp;
        for(int k=0; k<route.size(); k++) tmp.push_back(route[k]);
        visited[next] = true;
        tmp.push_back(next);
        dfs(next, sheep, wolf, tmp, info);
        visited[next] = false;
      }
    }
  }
}

int solution(vector<int> info, vector<vector<int>> edges)
{
  for (int i = 0; i < edges.size(); i++)
  {
    int from = edges[i][0];
    int to = edges[i][1];

    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  visited[0] = true;

  dfs(0, 0, 0, {0}, info);

  return answer;
}
