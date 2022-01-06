#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define endl '\n'


long long woobakCnt(long long num)
{
	long long res = 1;

	while (num != 1)
	{
		if (num % 2 == 0)
		{
			num /= 2;
		}
		else
		{
			num = (num * 3) + 1;
		}

		res++;
	}

	return res;
}

void solution() 
{
	int max = 0;
	int ans = 0;

	for (int i = 2; i < 1000001; i++)
	{
		int cnt = woobakCnt(i);

		if (cnt > max)
		{
			max = cnt;
			ans = i;
		}
	}

	cout << ans << endl;
}

int main() 
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}
