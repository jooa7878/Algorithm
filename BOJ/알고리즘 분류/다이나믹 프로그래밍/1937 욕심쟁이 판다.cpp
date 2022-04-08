#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

#define endl '\n';

using namespace std;

const int INF = 50000005;

int N;

int arr[501][501];
long long dp[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int y, int x)
{
  if (dp[y][x] != 0)
    return dp[y][x];

  dp[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (nx >= 0 && ny >= 0 && nx < N && ny < N && arr[y][x] < arr[ny][nx])
    {
      int res = dfs(ny, nx) + 1;
      if (res > dp[y][x])
        dp[y][x] = res;
    }
  }

  return dp[y][x];
}

void solution()
{
  int answer = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int res = dfs(i, j);
      if (res > answer)
        answer = res;
    }
  }

  cout << answer << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> arr[i][j];
    }
  }

  solution();
}
