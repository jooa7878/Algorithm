#include <iostream>
#include <vector>

using namespace std;

int N;
int answer;
int arr[1001];
pair<int, int> dp[1001];

void solution()
{
	
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	dp[1].first = 1;

	for (int i = 2; i <= N; i++)
	{
		int num = 0;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[j].first + 1  > num)
			{
				num = dp[j].first + 1;
			}
		}

		dp[i].first = num == 0 ? 1 : num;
	}

	dp[N].second = 1;
	for (int i = N-1; i > 0; i--)
	{
		int num = 0;
		for (int j = i+1; j <= N; j++)
		{
			if(arr[i] > arr[j] && dp[j].second + 1 > num)
			{
				num = dp[j].second + 1;
			}
		}
		dp[i].second = num == 0 ? 1 : num;
	}

	for (int i = 1; i <= N; i++)
	{
		if (dp[i].first + dp[i].second - 1 > answer)
			answer = dp[i].first + dp[i].second - 1;
	}
	
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	solution();

}

