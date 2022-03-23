#include <iostream>
#include <vector>
#include <queue>

#define endl '\n';
#define ll long long;

using namespace std;

int N, answer, furthest_node;
vector<pair<int, int> > adj[100001];
bool visited[100001];

void solution(int node)
{
  int res = 0;
  queue<pair<int, int> > q;

  q.push({0, node});
  visited[node] = true;
  while (!q.empty())
  {
    int distance = q.front().first;
    int node = q.front().second;
    if (distance > res)
    {
      res = distance;
      furthest_node = node;
    }
    q.pop();

    for (int i = 0; i < adj[node].size(); i++)
    {
      auto item = adj[node][i];
      int nDistance = item.first;
      int nNode = item.second;

      if (!visited[nNode])
      {
        visited[nNode] = true;
        q.push({distance + nDistance, nNode});
      }
    }
  }

  if (res > answer)
    answer = res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int node;
    cin >> node;
    while (true)
    {
      int from, weight;
      cin >> from;
      if (from == -1)
        break;
      cin >> weight;

      adj[node].push_back({weight, from});
    }
  }

  solution(1);
  for (int j = 1; j <= N; j++)
    visited[j] = false;
  solution(furthest_node);
  cout << answer << endl;
}
