#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 200000;
int N, K;
bool visited[MAX];


int solution()
{
	queue<pair<int, int>> q;

	q.push(make_pair(N, 0));

	visited[N] = true;

	while (!q.empty())
	{
		int pos = q.front().first;
		int step = q.front().second;

		q.pop();

		if (pos == K) return step;

		if (pos * 2 < MAX && !visited[pos * 2])
		{
			visited[pos * 2] = true;
			q.push(make_pair(pos * 2, step));
		}

		if (pos - 1 > 0 && !visited[pos - 1])
		{
			visited[pos - 1] = true;
			q.push(make_pair(pos - 1, step + 1));
		}

		if (pos + 1 < MAX && !visited[pos + 1])
		{
			visited[pos + 1] = true;
			q.push(make_pair(pos + 1, step + 1));
		}
		
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	if (N > K)
	{
		cout << N - K;
	}

	else
	{
		cout << solution();
	}
}

