#include <iostream>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int answer = 1;

void solution() {

	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		int max = 0;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[j] > max) max = dp[j];
			}
		}
		dp[i] = max + 1;
		if (dp[i] > answer) answer = dp[i];
	}
	
	cout << answer << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	solution();
}
