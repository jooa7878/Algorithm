#include <iostream>
#include <queue>

#define endl '\n';

using namespace std;

const int INF = 50000005;

int N;

int arr[101][101];
long long dp[101][101];

void solution()
{

  dp[0][0] = 1;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (dp[i][j] == 0 || arr[i][j] == 0)
        continue;
      int iTmp = i + arr[i][j];
      int jTmp = j + arr[i][j];

      if (iTmp >= 0 && iTmp < N)
      {
        dp[iTmp][j] += dp[i][j];
      }

      if (jTmp >= 0 && jTmp < N)
      {
        dp[i][jTmp] += dp[i][j];
      }
    }
  }

  cout << dp[N - 1][N - 1] << endl;
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
