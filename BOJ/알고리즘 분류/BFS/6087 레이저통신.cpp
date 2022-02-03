#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'

int W, H, answer = 987654321;
char arr[101][101];
bool visited[101][101][3];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
pair<pair<int,int>, pair<int, int>> pos;

void solution()
{
	priority_queue < pair<int, pair<pair<int, int>,int>>, vector< pair<int, pair<pair<int, int>, int>>>, greater< pair<int, pair<pair<int, int>, int>>>> pq;
	// {mirror, { {y, x}, direction }}
	pq.push({ 0,{{pos.first.first, pos.first.second}, 0 } });
	visited[pos.first.first][pos.first.second][0] = true;
	visited[pos.first.first][pos.first.second][1] = true;
	visited[pos.first.first][pos.first.second][2] = true;

	while (!pq.empty())
	{
		auto item = pq.top();
		int cnt = item.first;
		int y = item.second.first.first;
		int x = item.second.first.second;
		int direction = item.second.second;
		
		// direction : init = 0, vertical : 2, horizontal : 3
		if (y == pos.second.first && x == pos.second.second)
		{
			if (answer > cnt) answer = cnt;
		} 

		pq.pop();
		if (direction != 0 && visited[y][x][direction-1]) continue;
		visited[y][x][direction == 0 ? direction : direction-1] = true;
		//cout << y << ' ' << x << ' ' << cnt << ' ' << direction << endl;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (arr[ny][nx] != '*' && nx >= 0 && ny >= 0 && nx < W && ny < H)
			{
				if (direction == 0)
				{
					if (ny == y)
					{
						pq.push({ cnt, {{ny,nx},3} });
					}
					if (nx == x)
					{
						pq.push({ cnt, {{ny,nx},2} });
					}
				}
				else if (direction == 2)
				{
					if (nx != x && !visited[ny][nx][2]) 
					{
						pq.push({ cnt + 1,{{ny, nx},3} }); 
					}
					
					if(nx == x && !visited[ny][nx][1])
					{
						pq.push({ cnt, {{ny,nx},2} });
					}
				}
				else if (direction == 3)
				{
					if (ny != y && !visited[ny][nx][1])
					{
						pq.push({ cnt + 1, {{ny,nx},2} });						
					}
					if(ny == y && !visited[ny][nx][2])
					{
						pq.push({ cnt , {{ny,nx},3} });
					}
				}
			}
		}
		
	}
	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> W >> H;

	vector<pair<int, int>> tmp;

	for (int i = 0; i < H; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) 
		{
			arr[i][j] = str[j]; 
			if (str[j] == 'C' || str[j] == 'c') tmp.push_back({ i, j });
		}
	}

	pos = { tmp[0], tmp[1] };
	
	solution();
}
