#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

const int INF = 987654321;

int N, target, answer;
int arr[100001];

void solution()
{
	int left = 0, right = N-1;
	int sum = 0;

	while (left < right)
	{
		sum = arr[left] + arr[right];

		if (sum > target)
		{
			right--;
		}
		else if (sum < target)
		{
			left++;
		}
		else
		{
			answer++;
			left++;
			right--;
		}
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
		cin >> arr[i];
	}

	cin >> target;

	sort(arr, arr + N);

	solution();
}
