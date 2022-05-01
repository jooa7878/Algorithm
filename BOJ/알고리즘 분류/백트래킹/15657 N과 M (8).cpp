#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int ans[9];
int arr[9];


void dfs(int depth, int node) {

	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = node; i <= N; i++)
	{
		ans[depth] = arr[i];
		dfs(depth + 1, i);
	}

}

void solution() {
	dfs(0, 1);
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

	sort(arr + 1, arr + N + 1);

	solution();
}
