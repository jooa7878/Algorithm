#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int N;

void solution() 
{
	vector<int> vec(N);

	vector<int> lis;
	
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	lis.push_back(vec[0]);

	for (int i = 0; i < N; i++)
	{
		auto it = lower_bound(lis.begin(), lis.end(), vec[i]);

		int idx = it - lis.begin();

		if (it == lis.end())
		{
			lis.push_back(vec[i]);
		}
		else
		{
			lis[idx] = vec[i];
		}
	}

	cout << lis.size() << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	solution();
}
