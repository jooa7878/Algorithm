#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	bool flag = false;
	queue<pair<string,int>> q;


	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == target) 
		{
			flag = true;
			break;
		}
	}

	if (!flag) return 0;

	q.push(make_pair(begin,0));

	while (!q.empty())
	{
		string str = q.front().first;
		answer = q.front().second;

		if (str == target) break;

		q.pop();

		for (int i = 0; i < words.size(); i++)
		{
			int cnt = 0;
			for (int j = 0; j < words[i].length(); j++)
			{
				if (str[j] != words[i].at(j))
				{
					cnt++;
					if (cnt == 2) break;
				}
			}
			if (cnt == 1) q.push(make_pair(words[i], answer+1));
		}

	}
	

	return answer;
}
