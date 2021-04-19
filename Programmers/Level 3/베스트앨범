#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;
	unordered_map<string, int> hs;

	for (int i = 0; i < genres.size(); i++)
	{
		hs[genres[i]] += plays[i];
	}

	vector<pair<string, int>> vec(hs.begin(), hs.end());
	sort(vec.begin(), vec.end(), cmp);
	
	for (int i = 0; i < vec.size(); i++)
	{
		int cnt = 0;

		for (int j = 0; j < genres.size(); j++)
		{
			if (vec[i].first == genres[j])
			{
				cnt++;
			}
		}

		if (cnt == 1)
		{
			int max = 0;
			int idx = 0; 

			for (int j = 0; j < genres.size(); j++)
			{
				if (vec[i].first == genres[j] && plays[j] > max)
				{
					max = plays[j];
					idx = j;
				}
			}
			answer.push_back(idx);
		}
		else
		{
			for (int j = 0; j < 2; j++)
			{
				int max = 0;
				int idx = 0;
				for (int k = 0; k < genres.size(); k++)
				{
					if (vec[i].first == genres[k] && plays[k] > max)
					{
						max = plays[k];
						idx = k;
					}
				}
				answer.push_back(idx);
				plays[idx] = -1;
			}

		}
	}

	return answer;	
}
