#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int N, M;
vector<int> vec;

void solution()
{
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		int lb_idx = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
		int ub_idx = upper_bound(vec.begin(), vec.end(), num) - vec.begin();

		cout << ub_idx - lb_idx << ' ';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	cin >> M;

	solution();
}
