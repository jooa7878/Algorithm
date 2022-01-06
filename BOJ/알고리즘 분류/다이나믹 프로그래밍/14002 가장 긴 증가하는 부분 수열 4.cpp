#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int N;
int arr[1001];
int dp[1001];
vector<vector<int>> vec(1001);

void solution() 
{
	dp[0] = 1;
	vec[0].push_back({ arr[0] });
	int answer = 1;
	int idx = 0;
	
	for (int i = 1; i < N; i++)
	{
		int cnt = 0;
		vector<int> tmp;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[j] > cnt)
				{
					cnt = dp[j];
					tmp = vec[j];
				}
			}
		}
		
		dp[i] = cnt + 1;
		tmp.push_back(arr[i]);
		vec[i] = tmp;
		if (dp[i] > answer)
		{
			idx = i;
			answer = dp[i];
		}
	}

	cout << answer << endl;

	for (int i = 0; i < vec[idx].size(); i++)
	{
		cout << vec[idx][i] << ' ';
	}

	cout << endl;
}

int main() 
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	solution();
}
