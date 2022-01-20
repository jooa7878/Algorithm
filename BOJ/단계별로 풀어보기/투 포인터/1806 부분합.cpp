#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

const int INF = 2000000001;

int N, target;
int arr[100001];
int answer = INF;

void solution()
{
	int left = 0, right = 0;
	int sum = arr[0];
	int len = 1;


	while (left < N && right < N)
	{
		if (left == right)
		{
			
			if (sum >= target)
			{
				answer = 1;
				break;
			}
			else
			{
				right++;
				len++;
				sum += arr[right];
			}
		}
		else
		{
			if (sum >= target)
			{
				answer = min(answer, len);
				sum -= arr[left];
				len--;
				left++;
			}
			else
			{
				right++;
				len++;
				sum += arr[right];
			}
		}
	}
	
	
	if (answer == INF) cout << 0 << endl;
	else cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> target;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}


	solution();
}
