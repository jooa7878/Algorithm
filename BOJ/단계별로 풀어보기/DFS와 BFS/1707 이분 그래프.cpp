#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'

int K, V, E;
int visited[20001];
vector<int> vec[20001];

void solution(int start)
{
	visited[start] = 1;
	queue<pair<int, int>> q;
	q.push({ start, 1 });

	while (!q.empty())
	{
		int node = q.front().first;
		int color = q.front().second;
		q.pop();

		for (int i = 0; i < vec[node].size(); i++)
		{
			int pos = vec[node][i];
			if (visited[pos] == 0)
			{
				if (color == 1)
				{
					q.push({ pos, 2 });
					visited[pos] = 2;
				}
				else
				{
					q.push({ pos,1 });
					visited[pos] = 1;
				}
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;
		for (int j = 0; j < V; j++)
		{
			vec[j].clear();
		}

		for (int i = 0; i < 20001; i++)
		{
			visited[i] = 0;
		}

		for (int j = 0; j < E; j++)
		{
			int from, to;
			cin >> from >> to;

			vec[from - 1].push_back(to - 1);
			vec[to - 1].push_back(from - 1);
		}

		for (int j = 0; j < V; j++)
		{
			if (!visited[j])
			{
				solution(j);
			}
		}

		bool flag = true;

		for (int j = 0; j < V; j++)
		{
			for (int k = 0; k < vec[j].size(); k++)
			{
				if (visited[j] == visited[vec[j][k]])
				{
					flag = false;
					break;
				}
			}
		}

		if (flag) cout << "YES" << endl;
		else  cout << "NO" << endl;
	}
}
