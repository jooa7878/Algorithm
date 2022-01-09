#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int T, N, K, answer, idx;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void solution(int size) {
	int arr[126][126] = { 0, };
	int visited[126][126] = { 0, };
	vector<int> ans;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> arr[i][j];
			visited[i][j] = 2147483647;
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({{ 0, 0 }, arr[0][0]});
	visited[0][0] = arr[0][0];
	
	while (!q.empty())
	{
		auto item = q.front();
	
		if (item.first.first == size - 1 && item.first.second == size - 1)
		{
			ans.push_back(item.second);
		}

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = item.first.first + dx[i];
			int ny = item.first.second + dy[i];
			if (nx >= 0 && ny >= 0 && nx < size && ny < size)
			{
				int cost = item.second + arr[nx][ny];
				if (visited[nx][ny] > cost)
				{
					visited[nx][ny] = cost;
					q.push({ {nx, ny}, cost });
				}
			}
		}
	}

	sort(ans.begin(), ans.end());
	answer = ans[0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	while (true)
	{
		idx++;
		cin >> T;

		if (T == 0) break;
		
		solution(T);
		cout << "Problem " << idx << ": " << answer << endl;
	}
	
}
