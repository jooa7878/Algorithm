#include <iostream>
#include <queue>

using namespace std;

int N, M, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int poll() {
	int res = pq.top();

	pq.pop();

	return res;
}

void solution() {

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			ans = pq.empty() ? 0 : poll();
			cout << ans << '\n';
		}
		else
		{
			pq.push(num);
		}
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	solution();
}
