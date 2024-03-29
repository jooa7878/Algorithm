#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int N;
bool visited[1001][1001];

int solution()
{
	int emoji = 1;
	int clipboard = 0;
	visited[emoji][clipboard] = true;

	queue<pair<int, pair<int, int>>> q;

	q.push(make_pair(0, make_pair(emoji, clipboard)));


	while (!q.empty()) {

		int T = q.front().first;
		int E = q.front().second.first;
		int C = q.front().second.second;

		q.pop();

		if (E == N)
		{
			return T;
		}

		if (C == 0)
		{
			q.push(make_pair(T + 1, make_pair(E, E)));
			visited[E][E] = true;
		}
		else
		{
			if (E != C && !visited[E][E])
			{
				q.push(make_pair(T + 1, make_pair(E, E)));
				visited[E][E] = true;
			}
			if (E + C < N + 2 && !visited[E + C][C])
			{
				q.push(make_pair(T + 1, make_pair(E + C, C)));
				visited[E + C][C] = true;
			}
			if (!visited[E - 1][C] && E > 1)
			{
				q.push(make_pair(T + 1, make_pair(E - 1, C)));
				visited[E - 1][C] = true;
			}
		}
	}


	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cout << solution();
}

