// 20×20 격자의 좌상단에서 우하단으로 가는 경로의 수
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define endl '\n'

int answer = 0;
long long dp[21][21];

void solution()
{

	dp[0][0] = 1;

	for (int i = 0; i < 21; i++)
	{
		dp[i][0] = 1;
		dp[0][i] = 1;
	}

	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	
	cout << dp[20][20] << endl;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}
