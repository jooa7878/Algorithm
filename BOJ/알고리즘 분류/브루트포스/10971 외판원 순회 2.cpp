#include <iostream>
#include <algorithm>

using namespace std;

int N, answer = 1e9;
int arr[11][11];
int num[11];

/*

4
0 0 10 10
10 0 3 10
10 10 0 3
3 10 10 0

*/

void solution() {

	do {
		int cost = 0;
		int start = num[1];

		for (int i = 1; i < N; i++)
		{
			if (arr[num[i]][num[i + 1]] == 0)
			{
				cost = 1e9;
			}

			cost += arr[num[i]][num[i+1]];
		}

		cost += arr[num[N]][start];

		if (arr[num[N]][start] == 0) cost = 1e9;

		if (answer > cost)
			answer = cost;


	}while(next_permutation(num + 1, num + N + 1));

	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		num[i] = i;
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	solution();
}
