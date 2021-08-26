#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
long long arr[1000001];

int bSearch(long long arr[1000001]) {

	long long ans = 0;
	long long left = 0;
	long long right = arr[N];
	long long mid;

	while (left <= right)
	{
		long long sum = 0;
		mid = (left + right) / 2;

		for (int i = 1; i <= N; i++)
		{
			if(arr[i] > mid)
				sum += (arr[i] - mid);
		}

		if (sum >= M)
		{
			left = mid + 1;
			ans = mid;
			continue;
		}
		right = mid - 1;
	}


	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	sort(arr + 1, arr + N + 1);

	cout << bSearch(arr);

}
