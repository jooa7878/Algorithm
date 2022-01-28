#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'

int N;
long long answer;
long long duedate[100001];
long long plan[100001];

// first = plan, second = duedate
// plan 순서로 정렬하고
// 걔가 제일 작야아 함
// 근데 N^2은 안됨

void solution()
{
	vector<pair<long long, long long>> vec;

	for (int i = 0; i < N; i++)
	{
		vec.push_back({ plan[i], duedate[i] });
	}
	
	stable_sort(vec.begin(), vec.end());

	int prev = vec[0].first;
	int mx = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		if (prev > vec[i].second)
		{
			if (vec[i].first > prev) prev = vec[i].first;
			long long cnt = (prev - vec[i].second + 29) / 30;
			vec[i].second += cnt * 30;
			answer += cnt;
		}

		if (vec[i].second > mx) mx = vec[i].second;
		if (i + 1 < N && vec[i].first != vec[i + 1].first) prev = mx;
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> duedate[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> plan[i];
	}

	solution();
}
