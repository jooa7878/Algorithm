#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'
#define ll long long 

int N, M, answer;
int arr[200001];

void solution()
{
	sort(arr, arr + N);

	int left = 0;
	int right = arr[N - 1];
	vector<int> vec;

	while (left <= right)
	{
		vec.clear();
		int mid = (left + right) /2;
		vec.push_back(arr[0]);

		for (int i = 1; i < N; i++)
		{
			if (arr[i] >= vec[vec.size() - 1] + mid)
			{
				vec.push_back(arr[i]);
			}
		}

		if (vec.size() >= M)
		{
			answer = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	solution();
}
