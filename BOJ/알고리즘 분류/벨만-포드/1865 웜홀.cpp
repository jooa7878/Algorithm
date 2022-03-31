#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

#define endl '\n';

using namespace std;

const int INF = 50000000 + 5;

int T, N, M, W;
vector<pair<pair<int, int>, int> > road;
int dist[501];

void solution()
{
  cin >> N >> M >> W;

  for (int i = 1; i <= N; i++)
  {
    dist[i] = INF;
  }

  for (int i = 0; i < M; i++)
  {
    int from, to, weight;
    cin >> from >> to >> weight;
    road.push_back({{from, to}, weight});
    road.push_back({{to, from}, weight});
  }

  for (int i = 0; i < W; i++)
  {
    int from, to, weight;
    cin >> from >> to >> weight;
    road.push_back({{from, to}, -weight});
  }

  bool flag = true;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 0; j < road.size(); j++)
    {
      int from = road[j].first.first;
      int to = road[j].first.second;
      int distance = road[j].second;

      if (dist[to] > dist[from] + distance)
      {
        dist[to] = dist[from] + distance;
        if (i == N)
          flag = false;
      }
    }
  }

  if (flag)
  {
    cout << "NO" << endl;
  }
  else
  {
    cout << "YES" << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> T;

  for (int i = 0; i < T; i++)
  {
    solution();

    road.clear();
  }
}
