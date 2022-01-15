#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

const int INF = 10000001;
int N, M;
int arr[101][101];

void solution()
{
	for (int pos = 1; pos<=N; pos++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][j] > arr[i][pos] + arr[pos][j]) 
					arr[i][j] = arr[i][pos] + arr[pos][j];
			}
		}
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == INF) cout << 0 << ' ';
			else cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j) arr[i][j] = 0;
			else if (arr[i][j] == 0) arr[i][j] = INF;
		}

	}

	for (int i = 0; i < M; i++)
	{
		int from, to, time;
		cin >> from >> to >> time;
		if(arr[from][to] > time) arr[from][to] = time;
	}

	solution();
}
