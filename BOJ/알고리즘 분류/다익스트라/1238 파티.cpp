#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

const int INF = 2147483647;
int N, M, X, answer;
vector <pair<int, int>> vec[1001];
vector<pair<int, int>> from_vec[1001];
int dist[1001];
int from_dist[1001];

void toX()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}

	dist[X] = 0;
	pq.push({ dist[X], X });

	while (!pq.empty())
	{
		auto item = pq.top();
		pq.pop();
		int distance = item.first;
		int pos = item.second;

		if (dist[pos] == distance)
		{
			for (int i = 0; i < vec[pos].size(); i++)
			{
				auto next = vec[pos][i];
				int cost = next.first;
				int n_idx = next.second;

				if (dist[n_idx] > distance + cost)
				{
					dist[n_idx] = distance + cost;
					pq.push({ dist[n_idx], n_idx });
				}
			}
		}
	}
}

void fromX() {
	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

	for (int i = 1; i <= N; i++)
	{
		from_dist[i] = INF;
	}

	from_dist[X] = 0;
	pq.push({ from_dist[X], X });

	while (!pq.empty())
	{
		auto item = pq.top();
		pq.pop();
		int distance = item.first;
		int pos = item.second;

		if (from_dist[pos] == distance)
		{
			for (int i = 0; i < from_vec[pos].size(); i++)
			{
				auto next = from_vec[pos][i];
				int cost = next.first;
				int n_idx = next.second;

				if (from_dist[n_idx] > distance + cost)
				{
					from_dist[n_idx] = distance + cost;
					pq.push({ from_dist[n_idx], n_idx });
				}
			}
		}
	}
}

void solution() {
	toX();
	fromX();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M >> X;

	for (int i = 0; i < M; i++)
	{
		int from, to, time;
		cin >> from >> to >> time;
		vec[from].push_back({time,to});
		from_vec[to].push_back({time,from});
	}

	solution();

	for (int i = 1; i <= N; i++)
	{
		answer = max(answer, dist[i] + from_dist[i]);
	}

	std::cout << answer << endl;
}
