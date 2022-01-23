#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

// A 65 Z 90


int solution(string name) {
	int answer = 0;
	int cur = 0;
	int idx = 0;
	string cmp(name.length(), 'A');

	while (true)
	{
		answer += name[idx] > 78 ? 91 - name[idx] : name[idx] - 65;
		cmp[idx] = name[idx];

		if (name == cmp) return answer;

		int pos = idx;
		int left = 0, right = 0;

		// 왼쪽 검사
		while (cmp[pos] == name[pos])
		{
			pos--;
			left++;
			if (pos == -1)
			{
				pos = name.length()-1;
			}
		}

		pos = idx;

		// 오른쪽 검사

		while (cmp[pos] == name[pos])
		{
			pos++;
			right++;
			if (pos == name.length())
			{
				pos = 0;
			}
		}

		if (left >= right)
		{
			idx += right;
			answer += right;
		}
		else
		{
			if (idx > left)
				idx -= left;
			else
				idx = idx + name.length() - left;
			answer += left;
		}
	}

	return answer;
}
