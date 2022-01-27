#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

const int INF = 1600001;
int V, E, answer = INF;
int arr[401][401];

void solution()
{
	for (int k = 1; k <= V; k++)
	{
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (answer > arr[i][i]) answer = arr[i][i];
	}
	if (answer == INF) cout << -1 << endl;
	else cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> V >> E;

	memset(arr, INF, sizeof(arr));

	for (int i = 0; i < E; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		arr[from][to] = weight;
	}
	
	solution();
}
