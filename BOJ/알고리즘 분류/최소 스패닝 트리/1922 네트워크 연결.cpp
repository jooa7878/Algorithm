#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'
#define ll long long 

int N, M, answer;
vector<pair<int, int>> vec[1001];
bool visited[1001];

void solution()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < vec[1].size(); i++)
	{
		int nDistance = vec[1][i].first;
		int nNode = vec[1][i].second;

		pq.push({ nDistance, nNode });
	}

	visited[1] = true;

	while (!pq.empty())
	{
		int distance = pq.top().first;
		int node = pq.top().second;

		pq.pop();

		if (visited[node]) continue;
		visited[node] = true;
		answer += distance;
		for (int i = 0; i < vec[node].size(); i++)
		{
			int nDistance = vec[node][i].first;
			int nNode = vec[node][i].second;

			if (!visited[nNode]) pq.push({ nDistance, nNode });
		}
	}


	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to, weight;

		cin >> from >> to >> weight;

		vec[from].push_back({ weight, to });
		vec[to].push_back({ weight, from });
	}

	solution();
}
