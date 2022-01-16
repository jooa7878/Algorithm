#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int N, answer;
vector<long long> vec;

void solution()
{

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			if (i == j) continue;
			int num = vec[i] - vec[j];
			
			int ub_idx = upper_bound(vec.begin(), vec.end(), num) - vec.begin();
			int lb_idx = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
			int cnt = ub_idx - lb_idx; // 동일한 원소의 개수 (1인 경우 유일)
			if (lb_idx < vec.size() && vec[lb_idx] + vec[j] == vec[i])
			{
				if (vec[lb_idx] != vec[i] && vec[lb_idx] != vec[j] ||
					vec[lb_idx] == vec[i] && cnt > 2 ||
					vec[lb_idx] == vec[j] && cnt > 2 )
				{
					answer++;
					break;
				}
		
			}
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
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	solution();
}
