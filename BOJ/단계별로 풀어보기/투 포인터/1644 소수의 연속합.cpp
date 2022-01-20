#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'

const int INF = 2000000001;

int N, answer;
int arr[4000001];
vector<int> prime;

void solution()
{
	int left = 0, right = 0;
	int sum = prime[left];
	int size = prime.size();
	
	while (left < size && right < size)
	{
		if (sum <= N)
		{
			if (sum == N) answer++;
			right++;
			if(right < size) sum += prime[right];
		}
		else
		{
			sum -= prime[left];
			left++;	
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

	if (N == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 2; i <= N; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= N; j += i) arr[j] = 0;
	}

	for (int i = 2; i <= N; i++) if (arr[i] != 0) prime.push_back(i);

	solution();
}
