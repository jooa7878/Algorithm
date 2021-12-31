// 세자리 수를 곱해 만들 수 있는 가장 큰 대칭수
// 시간 복잡도 줄이는 방법?

#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

void solution() {

	int answer = 0;

	for (int i = 100; i < 1000; i++)
	{
		for (int j = 100; j < 1000; j++)
		{
			int num = i * j;
			string str = to_string(num);
			bool flag = true;
			for (int k = 0; k < str.length() / 2; k++)
			{
				if (str[k] != str[str.length() - k - 1])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				if (num > answer) answer = num;
			}
		}
	}

	cout << answer << endl;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	solution();
}
