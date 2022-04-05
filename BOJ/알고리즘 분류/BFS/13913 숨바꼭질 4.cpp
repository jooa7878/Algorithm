#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, K;
bool visited[100001];
vector<int> answer;

vector<int> solution()
{
	queue<pair<pair<int, int>, vector<int>>> q;
	vector<int> temp = { N };
	q.push(make_pair(make_pair(N, 0), temp));
	visited[N] = true;

	while (!q.empty())
	{
		int pos = q.front().first.first;
		int step = q.front().first.second;
		vector<int> tmp = q.front().second;

		q.pop();

		if (pos == K) { 
			cout << step << '\n';
			return tmp;
		}
		
		if (pos + 1 < 100001 && !visited[pos + 1])
		{
			tmp.push_back(pos + 1);
			q.push(make_pair(make_pair(pos + 1,step+1),tmp));
			tmp.pop_back();
			visited[pos + 1] = true;
		}
	
		if (pos > 0 && !visited[pos - 1])
		{
			tmp.push_back(pos - 1);
			q.push(make_pair(make_pair(pos - 1, step + 1), tmp));
			tmp.pop_back();
			visited[pos - 1] = true;
		}

		if (pos * 2 < 100001 && !visited[pos * 2])
		{
			tmp.push_back(pos * 2);
			q.push(make_pair(make_pair(pos* 2, step + 1), tmp));
			tmp.pop_back();
			visited[pos * 2] = true;
		}
	}


	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	if (N > K)
	{
		cout << N - K << '\n';
		for (int i = N; i >= K; i--)
		{
			cout << i << ' ';
		}
	}

	else
	{
		answer = solution();

		for (auto & a : answer)
		{
			cout << a << ' ';
		}
	}
}

