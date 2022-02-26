#include <string>
#include <vector>
#include <queue>

using namespace std;

int mod = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1));
	int answer = 0;

	for (int i = 0; i < puddles.size(); i++)
	{
		int x = puddles[i][0]; 
		int y = puddles[i][1];
        dp[y][x]= 0;

		if (x == 1)
		{
			for (int j = y; j <= n; j++)
			{
				dp[j][1] = 0;
			}
		}

		if (y == 1)
		{
			for (int j = x; j <= m; j++)
			{
				dp[1][j] = 0;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			if (dp[i][j] != 0)
			{
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
			}

		}
	}

	answer = dp[n][m];

	return answer;
}
