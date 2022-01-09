#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define endl '\n'

int N;

void solution()
{
	priority_queue<int, vector<int>> max_heap; // 내림차순 (최대힙)
	priority_queue<int, vector<int>, greater<int>> min_heap; // 오름차순(최소힙)

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (max_heap.size() == min_heap.size()) 
		{
			max_heap.push(num);
		}
		else
		{
			min_heap.push(num);
		}

		if (!max_heap.empty() && !min_heap.empty())
		{
			if (max_heap.top() > min_heap.top())
			{
				int mx = max_heap.top();
				int mn = min_heap.top();

				max_heap.pop();
				min_heap.pop();

				max_heap.push(mn);
				min_heap.push(mx);
			}
		}

		cout << max_heap.top() << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	solution();
}
