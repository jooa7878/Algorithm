#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;
const int INF = 2147483647;

int dist[MAX];
vector<pair<int, int>> adj[100001];

int V, E, src, dest;

struct cmp {

	bool operator()(pair<int, int>& a, pair<int, int> &b)
	{
		if (a.second == b.second)
			return a.first > b.first;
		
		return a.second > b.second;
	}
};

void solution() {

	priority_queue< pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push(make_pair(src, dist[src]));

	while (!pq.empty()) 
	{
		pair<int, int> cur = pq.top();
		pq.pop();
		int idx = cur.first;
		int distance = cur.second;

		if (dist[idx] == distance)
		{
			for (int i = 0; i < adj[idx].size(); i++)
			{
				pair<int, int> next = adj[idx][i];
				int n_idx = next.first;
				int cost = next.second;
				if (dist[n_idx] > distance + cost)
				{
					dist[n_idx] = distance + cost;
					pq.push(make_pair(n_idx, dist[n_idx]));
				}

			}
		}
	}

	cout << dist[dest] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		adj[from].push_back({ to, weight });
	}

	cin >> src >> dest;

	fill(dist, dist + V + 1, INF);

	dist[src] = 0;

	solution();
}
