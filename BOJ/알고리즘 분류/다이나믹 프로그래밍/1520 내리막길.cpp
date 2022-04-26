#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

#define endl '\n';

using namespace std;

int N, M, answer;
int arr[501][501];
int dp[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int y, int x)
{
  if (y == N - 1 && x == M - 1)
    return 1;

  if (dp[y][x] != -1)
    return dp[y][x];

  dp[y][x] = 0;
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && ny >= 0 && ny < N && nx < M && arr[y][x] > arr[ny][nx])
    {
      dp[y][x] += dfs(ny, nx);
    }
  }

  return dp[y][x];
}

void solution()
{
  answer = dfs(0, 0);

  cout << answer << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> arr[i][j];
      dp[i][j] = -1;
    }
  }

  solution();
}
