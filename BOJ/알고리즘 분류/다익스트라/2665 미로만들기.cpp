#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[51][51];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };
bool visited[51][51][51];
int answer;

void solution() {

	priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq;
	pq.push(make_pair(0, make_pair(0, 0))); // 0, [0,0];

	while (!pq.empty())
	{
		auto item = pq.top();
		int changed = item.first;
		int x = item.second.first;
		int y = item.second.second;

		pq.pop();

		if (x == N - 1 && y == N - 1)
		{
			answer = changed;
			break;
		}
	

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (arr[nx][ny] == 1 && !visited[changed][nx][ny] && nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				visited[changed][nx][ny] = true;
				pq.push(make_pair(changed, make_pair(nx, ny)));
			}
			else if(arr[nx][ny] == 0 && !visited[changed+1][nx][ny] && nx>=0 && ny>=0 && nx <N && ny < N)
			{
				visited[changed+1][nx][ny] = true;
				pq.push(make_pair(changed+1, make_pair(nx, ny)));
			}
		}
	}
	
	cout << answer << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		for (int j = 0; j < str.length(); j++) arr[i][j] = str[j] - '0';
	}

	solution();
}
