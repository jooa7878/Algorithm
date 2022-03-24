#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n';
#define ll long long;

using namespace std;

int T, N, answer;
pair<int, int> home, festival;
vector<pair<int, int> > conv;
bool flag;
bool visited[101];

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
  return (a.first + a.second) - (home.first + home.second) < (b.first - b.second) - (home.first - home.second);
}

void solution()
{
  flag = false;
  queue<pair<int, int> > q;

  q.push({home.first, home.second});

  sort(conv.begin(), conv.end());

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;

    q.pop();
    if (abs(festival.first - x) + abs(festival.second - y) <= 1000)
    {
      flag = true;
      return;
    }

    for (int i = 0; i < conv.size(); i++)
    {
      if (!visited[i])
      {
        if ((abs(conv[i].first - x) + abs(conv[i].second - y)) <= 1000)
        {
          visited[i] = true;
          q.push({conv[i].first, conv[i].second});
        }
      }
    }
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
    cin >> N;
    cin >> home.first >> home.second;
    for (int j = 0; j < N; j++)
    {
      int x, y;
      cin >> x >> y;
      conv.push_back({x, y});
    }
    cin >> festival.first >> festival.second;
    solution();
    if (flag)
    {
      cout << "happy" << endl;
    }
    else
    {
      cout << "sad" << endl;
    }

    for (int k = 0; k < N; k++)
      visited[k] = false;

    conv.clear();
  }
}
