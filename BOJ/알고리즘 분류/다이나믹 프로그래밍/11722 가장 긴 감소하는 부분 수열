#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001];
int  arr[1001];
int answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	dp[1] = 1;

	answer = 1;

	for (int i = 2; i<=N; i++)
	{
		int num = 0;
		for (int j = 1; j <i; j++)
		{
			if (arr[j] > arr[i] && dp[j] +1 > num)
			{
				num = dp[j] + 1;
			}
		}
		dp[i] = num == 0 ? 1 : num;
		
		if (num > answer) answer = num;
	}

	cout << answer;
}

