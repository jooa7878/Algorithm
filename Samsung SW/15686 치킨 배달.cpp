#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <cmath>

#define endl '\n';

using namespace std;

const int MAX = 2147483647;

int N, M, cnt, answer = MAX;
int arr[51][51];
int cpy[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int> > vec;
vector<pair<int, int> > house;
int ans[14];
bool v[14];
set<string> s;

void dfs(int depth, int node, string str)
{

  if (depth == M)
  {
    if (s.find(str) == s.end())
    {
      s.insert(str);
    }
    return;
  }

  for (int i = node; i < cnt; i++)
  {
    if (!v[i])
    {
      v[i] = true;
      dfs(depth + 1, i, str + to_string(i) + ' ');
      v[i] = false;
    }
  }
}

void solution()
{

  dfs(0, 0, "");
  for (auto str : s)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cpy[i][j] = arr[i][j];
      }
    }

    stringstream ss(str);
    string first;
    string tmp;
    while (getline(ss, tmp, ' '))
    {
      int num = stoi(tmp);
      cpy[vec[num].first][vec[num].second] = 5;
    }

    int res = 0;

    for (int i = 0; i < house.size(); i++)
    {
      int dist = MAX;
      for (int j = 0; j < vec.size(); j++)
      {
        if (cpy[vec[j].first][vec[j].second] == 5)
        {
          dist = min(dist, abs(house[i].first - vec[j].first) + abs(house[i].second - vec[j].second));
        }
      }
      res += dist;
    }

    if (answer > res)
      answer = res;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> arr[i][j];
      if (arr[i][j] == 2)
      {
        vec.push_back({i, j});
        cnt++;
      }
      else if (arr[i][j] == 1)
      {
        house.push_back({i, j});
      }
    }
  }

  solution();

  cout << answer << endl;
}
