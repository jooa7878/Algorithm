#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

const int INF = 2147483647;
int N, M;
vector<pair<pair<int,int>,int>> vec;
long long dist[501];

void solution()
{
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}

	dist[1] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <vec.size(); j++)
		{
			int from = vec[j].first.first;
			int to = vec[j].first.second;
			int time = vec[j].second;
			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + time) dist[to] = dist[from] + time;
		}
	}

	bool flag = true;

	for (int i =0; i <vec.size(); i++)
	{
		int from = vec[i] .first.first;
		int to = vec[i].first.second;
		int time = vec[i].second;
		if (dist[from] == INF) continue;
		if (dist[to] > dist[from] + time) 
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == INF) cout << -1 << endl;
			else cout << dist[i] << endl;
		}
	}
	else cout << -1 << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to, time;
		cin >> from >> to >> time;
		vec.push_back({ {from,to}, time });
	}

	solution();
}
