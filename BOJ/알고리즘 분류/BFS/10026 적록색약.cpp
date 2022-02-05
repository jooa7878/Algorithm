#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'

int N, answer;
char arr[101][101];
bool visited[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void solution(int y, int x, string person)
{
	queue<pair<int, int>> q;

	visited[y][x] = true;
	q.push({ y, x });
	
	char flag;

	if(person == "blind")
	{
		if (arr[y][x] == 'R' || arr[y][x] == 'G') flag = 'K';
		else flag = 'B';
	}
	else flag = arr[y][x];

	while (!q.empty())
	{
		auto item = q.front();
		int y = item.first;
		int x = item.second;

		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && ny < N && nx < N && !visited[ny][nx])
			{
				if (flag == 'K' && arr[ny][nx] == 'R' ||
					flag == 'K' && arr[ny][nx] == 'G')
				{
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
				else if (arr[ny][nx] == flag)
				{
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) arr[i][j] = str[j];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				answer++;
				solution(i, j, "normal");
			}
		}
	}
	cout << answer << ' ';

	memset(visited, false, sizeof(visited));
	answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				answer++;
				solution(i, j, "blind");
			}
		}
	}

	cout << answer << endl;
}
