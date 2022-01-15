#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

const long long INF = 21147483647;
int N, M, answer;
int sE, eE;
vector<pair<long long, long long>> vec[1001];
vector<long long > ans[1001];
long long dist[1001];

void solution(int idx)
{
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}

	dist[idx] = 0;
	pq.push({ dist[idx], idx });

	while (!pq.empty())
	{
		auto item = pq.top();
		pq.pop();
	
		long long distance = item.first;
		long long destination = item.second;
		
		if (dist[destination] < distance) continue;
		for (int i = 0; i < vec[destination].size(); i++)
		{
			auto next = vec[destination][i];
			long long cost = next.first;
			long long n_idx = next.second;
			
			if (dist[n_idx] > distance + cost)
			{
				dist[n_idx] = distance + cost;
                ans[n_idx]= {};
                ans[n_idx] = ans[destination];
		
				ans[n_idx].push_back(destination);
				pq.push({ dist[n_idx], n_idx });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		long long from, to, time;
		cin >> from >> to >> time;

		vec[from].push_back({ time, to });
	}

	cin >> sE >> eE;

	solution(sE);
	ans[eE].push_back(eE);
	cout << dist[eE] << endl;
	cout << ans[eE].size() << endl;
	for (auto a : ans[eE]) cout << a << ' ';
}
