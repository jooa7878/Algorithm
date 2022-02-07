#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N, M;
int arr[101][101];
bool visited[101][101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void solution() {

	vector<int> vec;

	deque<pair<pair<int, int>, int>> q;

	q.push_back(make_pair(make_pair(1, 1),0));
	
	visited[1][1][0] = true;

	while (!q.empty())
	{
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int crush = q.front().second;


		q.pop_front();

		if (nx == N && ny == M)
		{	
			cout << crush << '\n';
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];

			if (xx > 0 && yy > 0 && xx <= N && yy <= M && !visited[yy][xx][crush])
			{
				if (arr[yy][xx] == 1)
				{
					q.push_back(make_pair(make_pair(xx, yy), crush + 1));
					visited[yy][xx][crush] = 1;
					continue;
				}
				q.push_front(make_pair(make_pair(xx, yy), crush));
				visited[yy][xx][crush] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = str[j - 1] - '0';
		}
	}

	solution();
}

