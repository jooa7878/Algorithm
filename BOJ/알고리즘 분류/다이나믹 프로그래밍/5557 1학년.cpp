#include <iostream>
#include <queue>

#define endl '\n';

using namespace std;

const int INF = 50000005;

int N;

int arr[101];
long long dp[101][21];

void solution()
{

  dp[0][arr[0]] = 1;

  for (int i = 1; i < N; i++)
  {
    for (int j = 0; j < 21; j++)
    {
      if (dp[i - 1][j] == 0)
        continue;

      if (j - arr[i] >= 0)
        dp[i][j - arr[i]] += dp[i - 1][j];
      if (j + arr[i] <= 20)
        dp[i][j + arr[i]] += dp[i - 1][j];
    }
  }

  cout << dp[N - 2][arr[N - 1]] << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }

  solution();
}
