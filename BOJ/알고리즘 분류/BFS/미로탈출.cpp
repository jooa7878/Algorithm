#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int N, M, hx, hy, ex, ey;
int arr[1001][1001];
bool visited[1001][1001][2];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void solution() {
	queue<pair<pair<int, int>, pair<int,int>>> q;

	q.push(make_pair(make_pair(hx, hy), make_pair(0,0)));
	// posX, posY, 지팡이 사용 유무, 이동 횟수
	visited[hx][hy][0] = true;

	while (!q.empty())
	{
		auto item = q.front();

		q.pop();

		if (item.first.first == ex && item.first.second == ey)
		{

			cout << item.second.second << endl;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int x = item.first.first + dx[i];
			int y = item.first.second + dy[i];

			// 안부셨는데 1 또는 0을 만났거나 부셨고 0을 만났을 경우 q에 push
			if (item.second.first == 0)
			{
				if (x > 0 && y > 0 && x <= N && y <= M)
				{
					if (arr[x][y] == 0 && !visited[x][y][0])
					{
						q.push(make_pair(make_pair(x, y), make_pair(0, item.second.second + 1)));
						visited[x][y][0] = true;
					}
					else if (arr[x][y] == 1 && !visited[x][y][1])
					{
						q.push(make_pair(make_pair(x, y), make_pair(1, item.second.second + 1)));
						visited[x][y][1] = true;
					}
				}

			}
			else if (item.second.first == 1)
			{
				if (arr[x][y] == 0 && x > 0 && y > 0 && x <= N && y <= M && !visited[x][y][1])
				{
					q.push(make_pair(make_pair(x, y), make_pair(1, item.second.second + 1)));
					visited[x][y][1] = true;
				}
			}
		}
	}

	cout << -1 << endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;

	cin >> hx >> hy;

	cin >> ex >> ey;

	for (int i = 1;	i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}

	solution();
}
