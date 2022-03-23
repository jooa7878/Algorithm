#include <iostream>
#include <vector>
#include <queue>

#define endl '\n';
#define ll long long;

using namespace std;

int N;
int parents[100001];
vector<int> adj[100001];
bool visited[100001];

void solution()
{

  queue<int> q;
  visited[1] = 1;

  for (int i = 0; i < adj[1].size(); i++)
  {
    int num = adj[1][i];
    parents[num] = 1;
    q.push(num);
  }

  while (!q.empty())
  {
    int from = q.front();

    q.pop();

    if (visited[from])
      continue;
    visited[from] = true;
    for (int i = 0; i < adj[from].size(); i++)
    {
      int num = adj[from][i];
      if (parents[num] == 0)
        parents[num] = from;
      if (!visited[num])
        q.push(num);
    }
  }

  for (int i = 2; i <= N; i++)
  {
    cout << parents[i] << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N - 1; i++)
  {
    int from, to;

    cin >> from >> to;

    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  solution();
}
