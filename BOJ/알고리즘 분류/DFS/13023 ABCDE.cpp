#include <iostream>
#include <vector>

using namespace std;

int N, M, cnt, answer;
int arr[2001][2001];
vector<int> vec[2001];
bool visited[2001];

void dfs(int depth, int node, int cnt){

	if (depth == 5)
	{
		cout << 1;
		exit(0);
	}


	for (int i = 0; i < vec[node].size(); i++)
	{
		if (!visited[vec[node][i]])
		{
			visited[vec[node][i]] = true;
			dfs(depth + 1, vec[node][i], cnt + 1);
			visited[vec[node][i]] = false;
		}
	}
}

void solution() {

	for (int i = 0; i < N; i++)
	{
		visited[i] = true;
		dfs(1, i, 1);
		visited[i] = false;
	}

	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from;
		int to;

		cin >> from >> to;

		vec[from].emplace_back(to);
		vec[to].emplace_back(from);
	}
	
	solution();
}
