// 삼각형을 따라 내려가면서 합이 최대가 되는 경로 찾기

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define endl '\n'

int answer = 0;
int dp[15][15];

void solution()
{
	int arr[15][15] = {
		{75},
		{95, 64},
		{17, 47, 82},
		{18, 35, 87, 10},
		{20, 04, 82, 47, 65},
		{19, 01, 23, 75, 03, 34},
		{88, 02, 77, 73, 07, 63, 67},
		{99, 65, 04, 28, 06, 16, 70, 92},
		{41, 41, 26, 56, 83, 40, 80, 70, 33},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
		{63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
		{04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23}
	};

	
	dp[0][0] = arr[0][0];

	for (int i = 1; i < 15; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j-1], dp[i-1][j]) + arr[i][j];
		}
	}

	int answer = 0; 

	for (int i = 0; i < 15; i++)
	{
		if (dp[14][i] > answer) answer = dp[14][i];
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}
