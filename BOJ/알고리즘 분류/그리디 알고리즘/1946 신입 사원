#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
int answer;

void solution()
{
	int num = 100001;
	cin >> N;
	answer = N;
	vector<pair<int, int>> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].first >> vec[i].second;
	}

	stable_sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		if (vec[i].second < num)
		{
			num = vec[i].second;
			continue;
		}
		answer--;
	}

	cout << answer << '\n';
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> T;

	for (int i = 0; i < T; i++)
	{
		solution();
	}
}

