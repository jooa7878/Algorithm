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

int V, E, answer;
vector < pair < ll, ll>> vec[10001];
bool visited[10001];

void solution()
{
	priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	visited[1] = true;

	for (int i = 0; i < vec[1].size(); i++)
	{
		ll nDistance = vec[1][i].first;
		ll nNode = vec[1][i].second;

		pq.push({ nDistance, nNode });
	}

	while (!pq.empty())
	{
		ll distance = pq.top().first;
		ll node = pq.top().second;

		pq.pop();
		if (visited[node]) continue;
		visited[node] = true;
		answer += distance;


		for (int i = 0; i < vec[node].size(); i++)
		{
			ll nDistance = vec[node][i].first;
			ll nNode = vec[node][i].second;

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

	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;

		vec[from].push_back({ weight, to });
		vec[to].push_back({ weight, from });
	}

	solution();
}
