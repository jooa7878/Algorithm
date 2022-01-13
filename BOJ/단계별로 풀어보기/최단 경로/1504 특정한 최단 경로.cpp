ㅌㅡㄱㅂㅕ#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

const int INF = 214748367;
int N, E;
vector<long long> answer;
vector < pair<int, int> > vec[801];
int dist[801][801];

void solution(int idx)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

	for (int i = 1; i <= N; i++) dist[idx][i] = INF;

	dist[idx][idx] = 0;
	pq.push({ dist[idx][idx], idx });

	while (!pq.empty())
	{
		auto item = pq.top();
		pq.pop();
		int distance = -item.first;
		int destination = item.second;

		if (distance > dist[idx][destination]) continue;

		for (int i = 0; i < vec[destination].size(); i++)
		{
			auto next = vec[destination][i];
			int cost = next.first;
			int n_idx = next.second;

			if (dist[idx][n_idx] > distance + cost)
			{
				dist[idx][n_idx] = distance + cost;
				pq.push({ -dist[idx][n_idx], n_idx });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		int to, from, time;
		cin >> from >> to >> time;
		vec[from].push_back({ time,to });
		vec[to].push_back({ time, from });
	}

	int haveTo1, haveTo2;

	cin >> haveTo1 >> haveTo2;

	for(int i=1; i<=N; i++)
		solution(i);
	
	if (dist[1][haveTo1] == INF && dist[1][haveTo2] == INF)
	{
		cout << -1 << endl;
		return 0;
	}
 
	answer.push_back(dist[1][haveTo1] + dist[haveTo1][haveTo2] + dist[haveTo2][N]);
	answer.push_back(dist[1][haveTo2] + dist[haveTo2][haveTo1] + dist[haveTo1][N]);
	
	long long ans = answer[0] > answer[1] ? answer[1] : answer[0];

	if (ans >= INF) cout << -1 << endl;
	else cout << ans << endl;
}
