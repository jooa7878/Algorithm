// 1 ~ 20 사이의 어떤 수로도 나누어 떨어지는 가장 작은 수
#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

void solution() {

	long long num = 2520;

	while (true)
	{
		bool flag = true;
		for (int i = 2; i < 21; i++)
		{
			if (num % i != 0)
			{
				flag = false;
				break;
			}
		}

		if (flag) break;
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
