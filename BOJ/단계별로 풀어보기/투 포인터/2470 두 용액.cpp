#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

const int INF = 2000000001;

int N;
int arr[100001];
pair<int, int> answer;


void solution()
{
	int left = 0;
	int right = N - 1;
	int tmp = INF;
	int prev = 0;

	while (left < right)
	{
		int sum = arr[left] + arr[right];

		if (sum == 0)
		{
			answer.first = arr[left];
			answer.second = arr[right];
			break;
		}
		else if (abs(tmp) >=abs(sum))
		{
			answer.first = arr[left];
			answer.second = arr[right];
			tmp = sum;
			if (sum > 0) right--;
			else left++;
			
			
		}
		else if (abs(tmp) < abs(sum)) 
		{
			if (sum > 0) right--;
			else left++; 
		}
		
	}


	cout << answer.first << ' ' << answer.second;
	
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

	sort(arr, arr + N);

	solution();
}
