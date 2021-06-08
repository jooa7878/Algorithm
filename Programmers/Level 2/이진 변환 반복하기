#include <string>
#include <vector>

using namespace std;

string to_binary(int num)
{
	string s = "";

	while (num)
	{
		if (num % 2 == 0)
		{
			s.insert(s.begin(), '0');
		}
		else
		{
			s.insert(s.begin(), '1');
		}

		num /= 2;
	}
	return s;
}

vector<int> solution(string s) {
	vector<int> answer(2);
	int z_count = 0; // zero count
	int c_count = 0; // change count

	while (s != "1") {
		c_count++;
		string str = "";

		for (int i = 0; i < s.length(); i++)
		{

			if (s[i] == '1')
				str += '1';
			else
				z_count++;

		}

		s = to_binary(str.length());
	}

	answer[0] = c_count;
	answer[1] = z_count;

	return answer;
}
