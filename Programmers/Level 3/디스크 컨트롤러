#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp {
	bool operator ()(vector<int> a, vector<int> b)
	{
		return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int idx = 0;
	int time = 0;
	int N = jobs.size();

	sort(jobs.begin(), jobs.end());

	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

	while (N)
	{
		while (idx < jobs.size() && jobs[idx][0] <= time )
		{
			pq.push(jobs[idx]);
			idx++;
		}
		if (!pq.empty())
		{
			if (pq.top()[0] <= time)
			{
				answer += (time - pq.top()[0]) + pq.top()[1];
				time += pq.top()[1];
				pq.pop();
				N--;
			}
			else
			{
				time = pq.top()[1];
			}
		}
		else
		{
			time++;
		}
	}

	return answer / jobs.size();
}
