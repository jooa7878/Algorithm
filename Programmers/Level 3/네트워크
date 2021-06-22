#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer;
int adj[201][201];
bool visited[201] = { 0 };

void bfs(int node, int n, bool visited[201]) {
	queue<int> q;
	q.push(node);

	if (!visited[node]) {
		visited[node] = 1;
		answer++;
	}

	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		for (int i = 0; i < n; i++)
		{
			if (adj[num][i] == 1 && !visited[i])
			{
				visited[i] = 1;
				q.push(i);
			}
		}
		
	}

}

int solution(int n, vector<vector<int>> computers) {
	answer = 0;
	adj[201][201] = { 0 };

	for (int i = 0; i < computers.size(); i++) {
		for (int j = 0; j < computers[i].size(); j++)
		{
			adj[i][j] = computers[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		bfs(i, n, visited);
	}


	return answer;
}
