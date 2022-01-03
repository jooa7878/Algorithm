#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'

void solution() {

	int answer = 0;
	int num = 2;
	while (true)
	{
		bool flag = true;

		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num % i == 0)
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			answer++;
			if (answer == 10001) break;
		}
		num++;
	}

	cout << num << endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}
