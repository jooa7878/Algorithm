#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// deque 썼으면 훨씬 깔끔하고 효울적으로 풀 수 있었을듯 

vector<int> solution(vector<string> operations) {
	vector<int> answer(2);
	priority_queue<int> pq;

	for (int i = 0; i < operations.size(); i++)
	{

		if (operations[i].at(0) == 'I')
		{
			int num = stoi(operations[i].substr(2));
			pq.push(num);
		}
		else
		{
			if (!pq.empty()) {
				if (operations[i].at(2) == '1')
				{
					pq.pop();
				}
				else
				{
					priority_queue<int> temp;
					while (pq.size() > 1)
					{
						temp.push(pq.top());
						pq.pop();
					}
					pq.pop();
					pq = temp;
				}
			}
		}

	}

	if (pq.empty())
	{
		answer[0] = 0;
		answer[1] = 0;
	}
	else
	{
		answer[0] = pq.top();
		while (pq.size() > 1)
		{
			pq.pop();
		}
		answer[1] = pq.top();

	}


	return answer;
}
