#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'

int N, M, answer;
vector<int> vec[1001];
bool visited[1001];

void dfs(int idx) 
{

	for (int i = 0; i < vec[idx].size(); i++)
	{
		int pos = vec[idx][i];
		if (!visited[pos])
		{
			visited[pos] = true;
			dfs(pos);
		}
	}
}

void solution()
{
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			answer++;
			dfs(i);
		}
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;

		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	solution();
}
