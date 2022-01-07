// 2^1000의 각 자릿수를 모두 더하면?
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define endl '\n'

int answer = 0;

void solution()
{
	string str = "2";

	for (int i = 0; i < 999; i++)
	{
		bool overTen = false;
		reverse(str.begin(), str.end());
		for (int j = 0; j < str.length(); j++)
		{
			int tmp = (str[j] - '0') * 2;
			if (tmp >= 10)
			{
				string s = to_string(tmp);
				str[j] = overTen ? s[1] -'0' + 49 : s[1];
				overTen = true;
			}
			else
			{
				str[j] = overTen ? tmp + 49 : tmp + 48;
				overTen = false;
			}
		}
		if (overTen)
		{
			str += '1';
		}
		reverse(str.begin(), str.end());
	}

	
	for (int i = 0; i < str.length(); i++)
	{
		answer += str[i] - '0';
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}
