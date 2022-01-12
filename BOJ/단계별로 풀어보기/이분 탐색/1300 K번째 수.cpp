#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

long long N, K;

void solution() 
{
	long long cnt = 0;

	long long start = 1;
	long long end = K;
	long long answer = 0;

	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long tmp = 0;
		for (long long i = 1; i <= N; i++)
		{
			tmp += min(mid / i, N);
		}

		if (tmp < K) start = mid + 1;
		else 
		{
			answer = mid;
			end = mid - 1;
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
	cin >> K;

	solution();
}
