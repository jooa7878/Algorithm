#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool visited[9];
int ans[9];
int arr[9];


void dfs(int depth){

	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			ans[depth] = arr[i];
			visited[i] = true;
			dfs(depth + 1);
			visited[i] = false;
		}
	}

}

void solution() {
	dfs(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	sort(arr+1, arr + N+1);

	solution();
}
